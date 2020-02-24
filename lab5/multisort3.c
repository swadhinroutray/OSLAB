#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
int main(){
printf("Input number of strings: ");
    int n,i,j;
    int stat;
    scanf("%d", &n);
    char str[20][20],temp[20];
    printf("\n Input the strings \n");
    for( i = 0; i < n; i++)
    {
        scanf("%s",&str[i][20]);
    }
    pid_t pid1 = fork();
    pid_t pid2 = fork();

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
    // else if(pid1>0)
    // {
    //     printf("Failed child process");
    // } 


    //Process 2
    if(pid2 == 0){
        char minStr[20]; 
        for (i = 0; i < n-1; i++) 
        { 
            int min_idx = i; 
            strcpy(minStr, str[i]); 
            for (j = i+1; j < n; j++) 
            { 
                if (strcmp(minStr, str[j]) > 0) 
                { 
                    strcpy(minStr, str[j]); 
                    min_idx = j; 
                } 
            } 
    
            if (min_idx != i) 
            { 
                char temp[20]; 
                strcpy(temp, str[i]); 
                strcpy(str[i], str[min_idx]); 
                strcpy(str[min_idx], temp); 
            } 
        } 
        for(i = 0; i < n; i++)
            {
                puts(str[i]);
            }
    }
//   else if(pid2>0){
//       printf("Failed process");
//   }
  
  else{
      wait(&stat);
  } 
  if (WIFEXITED(stat)) 
        printf("Exit status: %d\n", WEXITSTATUS(stat)); 
    else if (WIFSIGNALED(stat)) 
        psignal(WTERMSIG(stat), "Exit signal"); 
} 


//   if(wait(&pid1))
//     {
//     printf("Im the parent \n");
//     printf("\n Child returned: %d\n", WEXITSTATUS(pid1));  
//     }
//     else if(wait(&pid2)){
//     printf("Im the parent \n");
//     printf("\n Child returned: %d\n", WEXITSTATUS(pid2));  
//     }
    
