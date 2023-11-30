/*
 The child process send two numbers to the parent process via message queue. The parent process calculate the sum and return via same message queue.
The child process print the result and exit. The parent process wait for completion of the child and then exit
 
 */


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/msg.h>

#define MQ_KEY 0x00000001

typedef struct ksu
{
        long type;
        int i,j,result;

}ksu_t;

int main()
{
        int mqid,s,ret;

        mqid = msgget(MQ_KEY, IPC_CREAT|0600);
        if(mqid <0)
        {
                perror("msgget() failed to make message queue\n");
                _exit(1);
        }

        ret = fork();
        if(ret == 0)
        {
                ksu_t n1;
                printf("Child   :   Enter the 2 number : ");
                scanf("%d%d",&n1.i,&n1.j);

                n1.type = 20;
                msgsnd(mqid,&n1,sizeof(ksu_t)-sizeof(n1.type),0);

                msgrcv(mqid,&n1,sizeof(ksu_t)-sizeof(n1.type), 04, 0);
                printf("Child   :   Sum of 2 number is %d\n", n1.result);
                
        }
        else
        {

            ksu_t n2;
            printf("Parent is waiting .... \n");

            msgrcv(mqid,&n2,sizeof(ksu_t)-sizeof(n2.type),20,0);

            n2.result = n2.i +n2.j;
            printf("Parent  :   Sum is calculated and send to child \n");

            n2.type = 04;
            msgsnd(mqid, &n2, sizeof(ksu_t)-sizeof(n2.type), 0);

            waitpid(-1,&s,0);


            msgctl(mqid, IPC_RMID, NULL);

        }


        return 0;
}
