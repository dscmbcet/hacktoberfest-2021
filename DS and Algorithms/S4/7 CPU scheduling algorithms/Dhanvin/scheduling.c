#include <stdio.h>
#define S 30
struct process
{
  int pid, bt, wt, tt, at, flag, prior,ct,done,at2,rbt;
}p[10],t[10],t2[10],temp;

int num;

void Waiting(int n)
{
  p[0].wt = 0;
  for (int  i = 1; i < n ; i++ )
  {
    {
      p[i].wt = (p[i-1].bt + p[i-1].wt +p[i-1].at)-p[i].at;
      if(p[i].wt<0)
      p[i].wt=0;
    }
  }
}

void TAT(int n)
{
  for (int  i = 0; i < n ; i++)
    p[i].tt = p[i].bt + p[i].wt;
}

void priort(int n)
{
  int i, j,te,val;
  p[0].ct = p[0].at + p[0].bt;
  p[0].tt = p[0].ct - p[0].at;
  p[0].wt = p[0].tt - p[0].bt;
  for (int i = 1; i < n; i++) 
  {
    te = p[i - 1].ct;
    int low = p[i].prior;
    for (int j = i; j < n; j++) 
    {
      if (te >= p[j].at && low >= p[j].prior)
      {
        low = p[j].prior;
        val = j;
      }  
    }
    p[val].ct = te + p[val].bt;
    p[val].tt = p[val].ct - p[val].at;
    p[val].wt = p[val].tt - p[val].bt;
    temp=p[val];
    p[val]= p[i];
    p[i]=temp;
  }
}

void sjf(int n)   
{
  int te, val;
  p[0].ct = p[0].at + p[0].bt;
  p[0].tt = p[0].ct - p[0].at;
  p[0].wt = p[0].tt - p[0].bt;
  for (int i = 1; i < n; i++)
  {
    te = p[i - 1].ct;
    int low = p[i].bt;
    for (int j = i; j < n; j++) 
    {
      if (te >= p[j].at && low >= p[j].bt) 
      {
        low = p[j].bt;
        val = j;
      }
    }
  p[val].ct = te + p[val].bt;
  p[val].tt = p[val].ct - p[val].at;
  p[val].wt = p[val].tt - p[val].bt;
  temp=p[val];
  p[val]= p[i];
  p[i]=temp;
  }
}

void input(int x)
{
  printf("Enter the number of processes\n");
  scanf("%d",&num);
  if(x==1)
  {
    for(int i=0;i<num;i++)
    {
      p[i].pid=i;
      printf("Enter the arrival time\n");
      scanf("%d",&p[i].at);
      p[i].at2=p[i].at;
      printf("Enter the burst time\n");
      scanf("%d",&p[i].bt);
      p[i].rbt=p[i].bt;
    }
  }
  if(x==2)
  {
    for(int i=0;i<num;i++)
    {
      p[i].pid=i;
      printf("Enter the arrival time\n");
      scanf("%d",&p[i].at);
      printf("Enter the burst time\n");
      scanf("%d",&p[i].bt);
      printf("Enter the priority\n");
      scanf("%d",&p[i].prior);
    }
  }
}

void sort(int n,int x)
{
  int i,j;
  if(x==1)
  {
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n-i-1; j++)
      {
        if ( p[j].at > p[j+1].at)
        {
          temp=p[j];
          p[j]=p[j+1];
          p[j+1]=temp;
        }      
      }      
    }
  }
  if(x==2)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n-i-1; j++)
      if (p[j].at > p[j+1].at)
      {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;    
      }
      else if(p[j].at == p[j+1].at && p[j].prior > p[j+1].prior)
      {
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }     
    }   
  }
}
int ready_que[S], front = -1, rear = -1;

void enQ(int pi) 
{
  if (front == -1)
  front = rear = 0;
  else
  rear = (rear + 1) % S;
  ready_que[rear] = pi;
}
int deQ() 
{
  int temp = ready_que[front];
  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % S;
  return temp;
}
int qE() 
  {
    return front == -1;
  }
int qC(int pi) 
  {
    if (ready_que[rear] == pi)
      return 1;
      for (int i = front; i != rear; i = (i + 1) % S) 
      {
        if (ready_que[i] == pi)
        return 1;
      }
    return 0;
  }

void robin(int y,int q)
{
  int n=y;
  int ti=0,flag1=0,clockw=0,clockt=0,clock,wait=0;
  float avgwt=0.0,avgta=0.0;
  for(int i=0;i<n;i++)
    {
      t[i]=p[i];
    }
  enQ(0);
  int k=0;
  clock=p[0].at;
  //clock=0;
  printf("\n| %7s | %10s | %12s | %12s | %16s |\n","Processes "," Arrival Time"," Burst time","Turn-Aound Time","Waiting Time");  
  while(!qE())
  {
  k=deQ();
    if(clock<t[k].at)
    clock=t[k].at;
    t[k].wt+=clock-t[k].at2;

    if(t[k].rbt>q)
    {
      clock+=q;
      t[k].at2=clock;
      t[k].rbt-=q;
    }
    else
    {
      clock+=t[k].rbt;
      t[k].ct=clock;
      t[k].tt=t[k].ct-t[k].at;
      t[k].done=1;
      printf("\n  %7d   %10d   %12d   %12d   %16d  ", p[k].pid,p[k].at, p[k].bt, t[k].tt, t[k].wt);  
      wait = wait+t[k].wt;
      clockt = clockt+t[k].tt; 
    }
    for(int i=k+1;i<n;i++)
    {
 
      if(t[i].at>clock)
      break;
      if( t[i].done==0 && !qC(i))
      {
      enQ(i);}
    }
    if(t[k].done==0){
    enQ(k);}
  }
  printf("\n");
  avgwt = (float)wait/y;
  avgta = (float)clockt/y;
  printf("\n\n Average waiting time = %f\n Average turn-around = %f.",avgwt,avgta);
}

void display(int x)
{
  int t_wt=0,t_tat=0;
  if(x==1)
  {
    printf("\n| %7s | %10s | %12s | %12s | %16s |\n","Processes "," Arrival Time"," Burst time","Waiting time","Turn around time");
    for (int  i=0; i<num; i++)
    {
      t_wt = t_wt + p[i].wt;
      t_tat = t_tat + p[i].tt;
      printf("   %d ",p[i].pid);
      printf("       \t %d ", p[i].at );
      printf("        \t   %d ", p[i].bt );
      printf("       \t   %d",p[i].wt );
      printf("       \t\t   %d\n",p[i].tt );
    }
  }
  if(x==2)
  {
    printf("\n| %7s | %10s | %12s | %12s | %16s | %16s |\n","Processes ","  Arrival Time" , "Burst time"  , "Prioity" , "Waiting time","Turn around time");
    for (int  i=0; i<num; i++)
    {
      t_wt = t_wt + p[i].wt;
      t_tat = t_tat + p[i].tt;
      printf(" %7d ",p[i].pid);
      printf(" %10d ", p[i].at );
      printf("  %12d ", p[i].bt );
      printf("  %12d ", p[i].prior );
      printf("  %16d ",p[i].wt );
      printf(" %16d\n",p[i].tt );
    }
  }
  float s=(float)t_wt / (float)num;
  float t=(float)t_tat / (float)num;
  printf("Average Waiting Time = %0.2f",s);
  printf("\n");
  printf("Average Turn around Time = %0.2f ",t);
  printf("\n");
}

int main()
{
  int choice=0;
  while(choice!=5)
  {
    printf("Menu\n");
    printf("ENTER THE CHOICE FOR QUEUEING\n");
    printf("1. First Come First Serve Algorithm\n");
    printf("2. Shortest Job First\n");
    printf("3. Priority\n");
    printf("4. Round Robin\n");
    printf("5. EXIT\n");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1: printf("Your Choice is First Come First Serve\n");
      printf("please enter the process list\n");
      input(1);
      sort(num,1);
      Waiting(num);
      TAT(num);
      display(1);
      break;
      case 2: printf("Your Choice is Shortest Job First\n");
      printf("please enter the process list\n");
      input(1);
      sort(num,1);
      sjf(num);
      display(1);
      break;
      case 3: printf("Your Choice is Priority\n");
      printf("please enter the process list\n");
      input(2);
      sort(num,2);
      priort(num);
      display(2);
      break;
      case 4: printf("Your Choice is Round Robin\n");
      input(1);
      sort(num,1);
      int slice;
      printf("Enter the time slice\n");
      scanf("%d",&slice);
      robin(num,slice);
      break;
      case 5:
      printf("Thank You For Using This Program\n");
      break;
      default:
      printf("Error\n");
      break;
    }
  }
}