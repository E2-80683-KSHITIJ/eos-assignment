#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
// parent A -> child B -> child C -> child D
int main() {
    int i, pidb, sb, pidc, sc,pidd, sd;

    // parent a
    pidb = fork();
    if(pidb == 0) { 
        // child b
        pidc = fork();
        if(pidc == 0) {
            pidd = fork();
            if(pidd == 0) {
               // child d
              for(i=1; i<=5; i++) {
                  printf("child D: %d\n", i);
                  sleep(1);
               }
                  waitpid(pidd, &sd, 0);
                  _exit(0);
        }
            // child c
            for(i=1; i<=5; i++) {
                printf("child C: %d\n", i);
                sleep(1);
            }
            _exit(0);
        }
        
        // child b
        for(i=1; i<=5; i++) {
            printf("Child B: %d\n", i);
            sleep(1);
        }
        waitpid(pidc, &sc, 0);
        _exit(0);
    }

    // parent a
    for(i=1; i<=5; i++) {
        printf("Parent A: %d\n", i);
        sleep(1);
    }
    waitpid(pidb, &sb, 0);

    return 0;
}