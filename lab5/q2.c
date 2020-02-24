#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
int status;
int n=argc;
char a[25][25];
for(int i=1;i<n;i++)
strcpy(a[i],argv[i]);
pid_t fr;
fr=fork();
if(fr==0)
{
   char t[25];
   for(int i=1;i<n;i++)
   {
     for(int j=1;j<n-i;j++)
      {
         if(strcmp(a[j],a[j+1])>0)
          {
             strcpy(t,a[j]);
             strcpy(a[j],a[j+1]);
             strcpy(a[j+1],t);
          }
      }
   }
printf("sorted is: \n");
for(int i=1;i<n;i++){printf("%s\n",a[i]);}
exit(0);
}
else{
wait(&status);
printf("\nunsorted is: \n");
for(int i=1;i<argc;i++)
printf("%s\n",argv[i]);
}
return 0;
}

