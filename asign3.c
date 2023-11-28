#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret, count = 0,status;

    while(1) {
        ret = fork();
        if(ret == -1)
            break;
        else if(ret == 0) {
            // child process
            sleep(5);
            _exit(0);
        }
        else {
            // parent process
            count++;
        }
    }
   
    printf("max child count: %d\n", count);
    while(waitpid(-1,&status,0)>0);


    return 0;
}