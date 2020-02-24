#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
printf("hello\n");
fork();
pid_t pid=getpid();
pid_t ppid=getppid();
printf(" %i %i \n",pid,ppid);
printf("bye\n");
return 0;
}
