/*
Group members
    1) Muhammad Yamin (021-19-0029)
    2) Muhammad Fahad Shahzad (051-19-0003)
    3) Muhammad Akram (051-19-0033)
    4) Irfan Ullah (051-19-0008)
    5) Wasid Khan (021-19-0022 )
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void fcfs(){
    int track_size,initial;
    printf("\nEnter the Track Size: ");
    scanf("%d",&track_size);
    int n,i;
    printf("\nEnter the no of Request: ");
        scanf("%d",&n);
        printf("\nEnter the Request queue: ");
        int arr[n];
        
        for (i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        

    printf("\nEnter the Initial Position of R/W Head: ");
    scanf("%d",&initial);
    arr[0]=initial;
    
    int seek_time=0,diff=0;
    for(i=0;i<n;i++)
    {
        diff=arr[i+1]-arr[i];
        if(diff<0)
        {
            seek_time=seek_time-diff;
        }
        else
        {
            seek_time=seek_time+diff;
        }
    }
    
    printf("Total Seek Time is %d",seek_time);
    printf("\n");
}
void sstf(){
    int track_size,current_position;
    printf("Enter the Size of Track: ");
    scanf("%d",&track_size);
    track_size=track_size-1;
    
    int n,i;
    printf("Enter the no of Request: ");
        scanf("%d",&n);
        printf("Enter the Request queue: ");
        int arr[n];
        int visited[n];
        for (i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            visited[i]=0;
        }
        

    printf("Enter the Current Position of R/W head: ");
    scanf("%d",&current_position);
    
    int min=1000,diff=5000,flag=7,seek_time=0;
    int j;
    for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                    if(visited[j]==0)
                    {
                    diff=arr[j]-current_position;
                    if(diff<0)
                    {
                        diff=-diff;
                    }   

                    if(diff<min)
                        {
                            min=diff;
                            flag=j;
                        }
                    }
        
            }
            
            visited[flag]=1;
            seek_time=seek_time+min;
            min=1000;
            diff=5000;
            current_position=arr[flag];
        }
    
    printf("Total Seek Time %d",seek_time);
    printf("\n");
}

int main()
{
	printf("\n------------------------------------------\n ");
	printf(" Main Menu for Disk Scheduling Algorithm \n");
	printf("------------------------------------------\n\n");
	printf("Press 1 for 'First Come First Serve' \n");	
	printf("Press 2 for 'Shortest Seek Time First' \n");
	printf("Press 0 for 'EXIT' \n");
	printf("\n------------------------------------------\n");
	int choice ;
	printf("Enter Your Choice : ");
	 scanf("%d",&choice);	
	
     
     switch(choice)
     {
         case 1:
           	fcfs();
           break;      
         case 2:
           	sstf();
           break;       
         case 0:
         	exit(1);
          break;	           
         default:
           printf("Invalid Choice");
    }
    return 0;
}
