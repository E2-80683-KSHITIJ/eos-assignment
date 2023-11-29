#include <stdio.h>
#include <unistd.h>
#include <signal.h>



int main() {
   
  // while (1)
   {
   
   int id, proc_id,i;
   printf("you are going to delete the process !!!!\n");

   printf("Enter the signal number : ");
   scanf("%d", &id);
   printf("\n");


   printf("Enter the process id : ");
   scanf("%d", &proc_id);
   printf("\n");

   i = kill(proc_id,id);
   if(i==0) 
    printf("the process is succesffuly killed\n");
    else
        printf("kill function is failed\n");
   }
    return 0;
}
