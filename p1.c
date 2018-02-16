#include <stdio.h>
#include <stdlib.h>

void * binsch(void * x)
{
int *y = (int *) (x);
int n = *y;
y++;
int i;
int * z=y;
for (i=0;i<n; i++)
z++;
int key= *z;
int low =0;
int high=n-1;
int mid;
while(low<high)
{
mid= (low+high)/2;
if(y[mid]==key){
printf("found");
break;
}
else
if(key>y[mid])
low=mid+1;
else
high=mid-1;
}
pthread_exit(0);
}
int main()
{
pthread_t tid;
int n, key, a[20],i;
printf("Enter no of elements:");
scanf("%d", &n);
a[0]=n;
printf("Enter elements:");
for(i=1; i<=n; i++)
scanf("%d", &a[i]);
printf("Enter key:");
scanf("%d", &key);
a[n+1]=key;
pthread_create(&tid, NULL, binsch, a);
pthread_join(tid, NULL);
printf("end");
}
