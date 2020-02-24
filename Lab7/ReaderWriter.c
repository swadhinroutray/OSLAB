#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t  mutex,writerbolock;
int reader=0,data=0;

void *Reader(void *arg){
int f = (int) arg;
sem_wait(&mutex);
reader+=1;
if(reader==1)
sem_wait(&writerbolock);
sem_post(&mutex);
printf("Data read by user %d is %d \n",f,data);
sleep(1);
sem_wait(&mutex);
reader-=1;
if(reader==0){
    sem_post(&writerbolock);
}
sem_post(&mutex);
}

void *Writer(void *arg){
    int f = (int) arg;
    sem_wait(&mutex);
    data++;
    printf("Data written by writer %d is %d \n",f,data);
    sem_post(&mutex);

}
int main(){
    int i,b;
    pthread_t rtid[10],wtid[10];
    sem_init(&mutex,0,1);
    sem_init(&writerbolock,0,1);
    printf("Input Data amount: ");
    int n;
    scanf("%d", &n);
     for(i=0;i<n;i++)
  {
    pthread_create(&wtid[i],NULL,Writer,(void *)i);
    pthread_create(&rtid[i],NULL,Reader,(void *)i);
  }
  for(i=0;i<n;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  printf("\n");
return 0;    
    
}