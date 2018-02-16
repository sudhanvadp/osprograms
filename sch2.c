#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<sched.h>

void printpolicy(int policy)
{
if(policy==SCHED_FIFO) printf("policy= %d FIFO\n", policy);
else if(policy==SCHED_RR) printf("Policy = %d Round robin\n", policy);
else if(policy==SCHED_OTHER) printf("Policy = %d other\n", policy);
}
void main(int argc, char * avrv[])
{
int policy;
struct sched_param p;
policy = sched_getscheduler(0);
printpolicy(policy);

printf("Trying sched scheduler with fifo\n");
policy=SCHED_FIFO;
p.sched_priority=20;
printf("%d",sched_setscheduler(0,policy, &p));
printpolicy(sched_getscheduler(0));

}
