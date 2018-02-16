#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * fibb (void *a)
{
int x=*((int *) (a));
pthread_t tid;
int b1,b2, b3;
int *a1,*a2;
if(x==1)
pthread_exit(&x);
else
if(x==0)
pthread_exit(&x);
else
{
b1=x-1;
b2=x-2;
pthread_create(&tid, NULL, fibb, &b1);
pthread_join(tid,a1);
pthread_create(&tid, NULL, fibb, &b2);
pthread_join(tid,a2);
b3=*a1+*a2;
pthread_exit(&b3);
}
}


int main()
{
pthread_t tid;
int x;
printf("Enter no: ");
scanf("%d", &x);
int i, y;
for (i = 0; i<x; i++)
{
pthread_create(&tid, NULL, fibb, &x);
pthread_join(tid, void **b);
y=*((int **) (b));
printf("Factorial = %d",y);
}
exit(0);
}
