#include<stdio.h>
int b[9];
void sort(int a[],int n)
{
	int i,temp,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
}
void main()
{
	int i,current=0,n,ct[10],sum=0,tat[10],wt[10],bt[10],a[10];
	float avgwt,avgtat;
	n=5;
	printf("Enter the burst  and at \n");
	for(i=0;i<n;i++){
		b[i]=i;
		printf("program  %d \n",i+1);
		printf("burst time[%d]:  ",i+1);
		scanf("%d",&bt[i]);
		printf("arrival time[%d]:  ",i+1);
		scanf("%d",&a[i]);
	}
	sort(a,n);
	current=a[b[0]];
	for(i=0;i<n;i++){
		current=bt[b[i]]+current;
		ct[b[i]]=current;
	}
	for(i=0;i<n;i++){
		wt[i]=ct[i]-bt[i]-a[i];
		sum+=wt[i];
	}
	avgwt=(float)sum/n;
	sum=0;
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		sum+=tat[i];
	}
	avgtat=(float)sum/n;
	printf("tat\twt\tct\n");
	for(i=0;i<n;i++){ 
		printf("%d\t%d\t%d\n",tat[i],wt[i],ct[i]);
	}
	printf("%f\t %f \n",avgtat,avgwt);
}
