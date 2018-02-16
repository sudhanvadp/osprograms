#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>

sem_t x;
int count=0;

void * inc()
{
sem_wait(&x);
count++;
printf("%d\n", count);
sem_post(&x);
}
void * dec()
{
sem_wait(&x);
count--;
printf("%d\n", count);
sem_post(&x);
}

int main()
{
sem_init(&x,1,1);
pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
pthread_t tid4;
pthread_t tid5;
pthread_t tid6;

pthread_create(&tid1,NULL, inc, NULL);
pthread_create(&tid2,NULL, inc, NULL);
pthread_create(&tid3,NULL, inc, NULL);
pthread_create(&tid4,NULL, dec, NULL);
pthread_create(&tid5,NULL, dec, NULL);
pthread_create(&tid6,NULL, dec, NULL);
pthread_join(tid1);
pthread_join(tid2);
pthread_join(tid3);
pthread_join(tid4);
pthread_join(tid5);
pthread_join(tid6);
}
