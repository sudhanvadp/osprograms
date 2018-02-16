#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sched.h>
#include<sys/time.h>
#include<sys/resource.h>

main(int argc, char * argv[])
{
int mypid, oldprio, newprio,i;
if(argc>1)
{
mypid=atoi(argv[1]);
}
else
{
mypid=getpid();
}
printf("pid=%d\n", mypid);
for(i=-20;i<20;i++)
{
oldprio=getpriority(PRIO_PROCESS, (int)mypid);
setpriority(PRIO_PROCESS, (int)mypid, i);
newprio=getpriority(PRIO_PROCESS, (int)mypid);
printf("old=%d, requested=%d, new=%d\n", oldprio, i, newprio);
}
}

