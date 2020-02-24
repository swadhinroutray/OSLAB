#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(){
    printf("Input number of strings: ");
    int n,i,j;
    scanf("%d", &n);
    char str[20][20],temp[20];
    printf("\n Input the strings \n");
    for( i = 0; i < n; i++)
    {
        scanf("%s",&str[i][20]);
    }
    pid_t pid1 = fork();
    if(pid1 == 0){
        printf("Child process id: %d \n", getpid());
        printf("Sorting strings \n");
        for( i = 0; i < n-1; i++)
        {
           for( j= i+1; j < n; j++)
           {
               if(strcmp(str[i],str[j])>0)
               {
                   strcpy(temp,str[i]);
                   strcpy(str[i],str[j]);
                   strcpy(str[j],temp);
               }
           }
           
        }
        for(i = 0; i < n; i++)
        {
            puts(str[i]);
        }
    }
    else if(pid1>0)
    {
        printf("Failed child process");
    } 
    else{
        printf("This plan has completly failed");
    }
}