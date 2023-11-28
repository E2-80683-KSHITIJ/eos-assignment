#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
    int i, pid[5];
    int s[5];

    for(int j=1;j<6;j++)
    {
        pid[j] = fork();
        if(pid[j] == 0)
        {
            for(i=0;i<=5;i++)
            {
                 printf("Child[%d] : %d ---> pid = %d\n",j,i,getpid());
                sleep(2);
            }
             _exit(0);

        }
    }

    for(i=1; i<=5; i++) {
        printf("Parent:  %d ---> pid = %d\n",i,getpid());
        sleep(2);
    }

    for(int j; j<6;j++)
    {
        waitpid(pid[j],&s[j], 0);
        //printf("child [%d] exit status : %d\n", ret, WEXITSTATUS(s[j]));
    }
  

    return 0;
}