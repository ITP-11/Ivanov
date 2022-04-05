#include<stdio.h>
#include<string.h>
#include<conio.h>
struct PCB
{
       int pid, arrival, burst, turnaround;
};
int main()
{
      int i, num, j;
      float avg = 0, sum = 0;
      struct PCB p[10], temp;
      printf("Enter number of processes: ");
      scanf("%d", &num);
      for(i = 0; i < num; i++)
      {
            printf("Process %d:\n", i+1);
            printf("Enter arrival time: ");
            scanf("%d", &p[i].arrival);
            printf("Enter burst time: ");
            scanf("%d", &p[i].burst);
            p[i].pid = i+1;
      }
      for(i = 0; i < num-1; i++)
      {
            for(j = 0; j < num-1; j++)
            {
                if(p[j].arrival > p[j+1].arrival)
                {
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }

            }
      }
      for(i = 0; i < num; i++)
      {
            sum += p[i].burst;
            p[i].turnaround = sum;
      }
      sum = 0;
      printf("--------------------------------------------");
      printf("\n");
      printf("PID\tArrival\tBurst\tTurnaround\n");
      printf("--------------------------------------------");
      printf("\n");
      for(i = 0; i < num; i++)
      {
            printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].turnaround);
            sum += p[i].turnaround;
      }
      avg = sum/(float)num;
      printf("\nTotal Turnaround Time: %.4f", sum);
      printf("\nAverage Turnaround Time: %.4f", avg);
      printf("\n ");
      for(i = 0; i < num; i++)
      {
               for(j = 0; j < p[i].burst; j++)
                        printf("--");
               printf(" ");
      }
      printf("\n|");
      for(i = 0; i < num; i++)
      {
            for(j = 0; j < p[i].burst - 1; j++)
                printf(" ");
            printf("P%d", p[i].pid);
            for(j = 0; j < p[i].burst - 1; j++)
                printf(" ");
            printf("|");
      }
      printf("\n ");
      for(i = 0; i < num; i++)
      {
            for(j = 0; j < p[i].burst; j++)
                printf("--");
            printf(" ");
      }
      printf("\n");
      printf("0");
      for(i = 0; i < num; i++)
      {
            for(j = 0; j < p[i].burst; j++)
                printf("  ");
            printf("%d", p[i].turnaround);
      }
      fflush(stdin);
      getchar();
      return 0;
}
