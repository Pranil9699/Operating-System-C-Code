#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
int PID,AT,BT,ST,FT,TAT,WT;
}Process;

int compare_processes(const void *a,const void *b){
Process *p1=(Process *)a;
Process *p2=(Process *)b;
return p1->AT-p2->AT;
}
void printGanttChart(Process *processes,int n){
printf("Gantt Chart: \n");
for(int i = 0 ; i< n ; i++){
printf("%d | %d - %d\n",processes[i].PID,processes[i].ST,processes[i].FT);
}
}

void printAverageTimes(Process *processes,int n){
float TTAT=0.0;
float TWT=0.0;
for(int i=0;i<n;i++){
TTAT+=processes[i].TAT;
TWT+=processes[i].WT;
}

float ATAT=TTAT/n,AWT=TWT/n;

printf("Average TAT : %f\n",ATAT/5);
printf("Average WT : %f\n",AWT/5);
}

int main(){
srand(time(NULL));
int n;
printf("Enter the Number of Processes: ");
scanf("%d",&n);

Process *processes = (Process *)malloc(n*sizeof(Process));

for(int i =0 ; i< n ; i++){

printf("Enter the Arrival time of process %d ",i);
scanf("%d",&processes[i].AT);

printf("Enter the CPU Burst time of process %d ",i);
scanf("%d",&processes[i].BT);

}

qsort(processes,n,sizeof(Process),compare_processes);

int current_time = 0;

for(int i=0; i< n ; i++){

if(processes[i].AT>current_time){
current_time=processes[i].AT;
}

processes[i].ST=current_time;

int next_CPU_B=rand()%10+1;
processes[i].BT+=next_CPU_B;

processes[i].FT=current_time+processes[i].BT;

current_time=processes[i].FT;
}

for(int i=0;i<n;i++){
processes[i].TAT=processes[i].FT-processes[i].AT;
processes[i].WT=processes[i].TAT-processes[i].BT;
}
printGanttChart(processes,n);
printAverageTimes(processes,n);
free(processes);
return 0;
}














