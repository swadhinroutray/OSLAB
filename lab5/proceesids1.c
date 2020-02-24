#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){
    printf("Hello \n");
    pid_t pid1 = fork();
    
    if(pid1>0){
    
    printf("Parent process id:  %d \n", getppid());
    }
    else if(pid1==0)
    {   
        printf("Parent process id: %d \n",getppid());
        printf("Child Process id: %d \n", getpid());
    }
    else{
        printf("Hello");
    }
    return 0;
}