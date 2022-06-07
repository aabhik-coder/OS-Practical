#include<stdio.h>
#include<conio.h>
struct process{
	int sn;//process number
	int at;//arrival time
	int bt;//burst time
	int et;//exit time
	int tt;//turnaround time
	int wt;//waiting time
};
typedef struct process process;
int main()
{
process p[5],temps;
int i,j,ct,temp,tempp,tempb;
float sumtt,sumwt;
//Input the table
printf("Enter the Arrival time and Burst time of processes: \n");
for(i=0;i<5;i++)
{
	p[i].sn=i;
	printf("\nProcess p%d: ",i);
	printf("\nArrival time: ");
	scanf("%d",&p[i].at);
	printf("Burst time: ");
	scanf("%d",&p[i].bt);
}
//sorting the process on the basis of arrival time
for(i=0;i<5;i++)
{
	for(j=i+1;j<5;j++)
	{
		if(p[j].at<p[i].at)
		{
			temps=p[i];
			p[i]=p[j];
			p[j]=temps;
		}	
	}
}
//Individual Exit time and TT and WT calculation
p[0].et=p[0].bt;
for(i=0;i<5;i++)
{	
	if(i>0)
	p[i].et=p[i-1].et+p[i].bt;
	p[i].tt=p[i].et-p[i].at;
	p[i].wt=p[i].tt-p[i].bt;
	sumtt=sumtt+p[i].tt;
	sumwt=sumwt+p[i].wt;
}
//displaying final info
printf("PR. No \t Arival Time \t Burst time \t Turnover \t Waiting Time\n");
for(i=0;i<5;i++)
	{
		printf("%d \t %d \t\t %d \t\t %d \t\t %d\n",p[i].sn,p[i].at,p[i].bt,p[i].tt,p[i].wt);
	}

//calculation of the Average turnaround time and waiting time
printf("\nAverage turnaround time:%f",(sumtt)/5);
printf("\nAverage waiting time:%f\n ",(sumwt)/5);	

}
