#include<stdio.h>
int front=-1,rear=-1,q[100];
int min(int a[],int n)
{
	int i=0,min=a[i],ind=i;
	for(i=0;i<n;i++){
		if(min>a[i]){
			min=a[i];
			ind=i;
		}
	}
	return ind;
}
void enqueue(int val)
{
	q[++front]=val;
}
int dequeue()
{
	return q[++rear];
}
int isempty()
{
	if(front==rear && front!=-1 && rear!=-1)
		return 1;
	else 
		return 0;
}
int search(int k)
{
	int i;
	printf("in search\n");
	for(i=rear+1;i<=front;i++){
		printf("%d\n",q[i]);
		if(q[i]==k){
			return 1;
		}
	}
	return 0;
}
void main()
{
	int at[10],bt[10],tat[10],wt[10],at_d[10],bt_d[10],ct[10];
	int i,n,current=0,tq,k,j,ind,sum=0;
	float avgwt,avgtat;
	
	n=3;
	printf("enter bt and at\n");
	for(i=0;i<n;i++){
		printf("program %d\n",i+1);
		printf("at[%d]: ",i+1);
		scanf("%d",&at[i]);
		at_d[i]=at[i];
		printf("bt[%d]: ",i+1);
		scanf("%d",&bt[i]);
		bt_d[i]=bt[i];
	}
	
	printf("time quantum: ");
	scanf("%d",&tq);
	enqueue(min(at_d,n));
	int count=1;
	while(!isempty()){
		ind=dequeue();
		printf("%d time and %d is poped\n",count++,ind);
	  for(j=0;j<tq;j++){
		current=current+1;
		bt_d[ind]=bt_d[ind]-1;		
	  	if(bt_d[ind]==0){
			ct[ind]=current;
			break;
		}
	   }
	  for(k=0;k<n;k++){
		  if(k==ind)
			  continue;
		  if(bt[k]==bt_d[k] && current>=at[k] && !search(k)){
			  printf(" in,== %d is pushed\n",k);
			  	enqueue(k);
		  }
		  if(bt[k]!=bt_d[k] && bt_d[k]!=0 && !search(k)){
			       printf("in !=,%d is pusged\n",k);
			  	enqueue(k);
		}
	  }
	  if(bt_d[ind]!=0){
		  printf("%d is pushed\n",ind);
		  enqueue(ind);
	   }
	}
	printf("\n\n\n");
	for(i=0;i<n;i++){
		wt[i]=ct[i]-bt[i]-at[i];
		sum+=wt[i];
	}
	avgwt=(float)sum/n;
	sum=0;
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		sum+=tat[i];
	}
	avgtat=(float)sum/n;
	printf("ct\t wt\t tat\n");
	for(i=0;i<n;i++)
		printf("%d\t %d\t %d\n",ct[i],wt[i],tat[i]);
	printf("avgwt=%f and avgtat=%f\n",avgwt,avgtat);
}
