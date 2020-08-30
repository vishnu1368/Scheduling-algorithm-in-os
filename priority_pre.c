#include<stdio.h>
int s[10];
void sort(int bt[],int n)
{
        int i,j,temp;
        for(i=0;i<n-1;i++)
                for(j=0;j<n-i-1;j++){
                                if(bt[j+1]<bt[j]){
                                        temp=bt[j];
                                        bt[j]=bt[j+1];
                                        bt[j+1]=temp;
                                        temp=s[j];
                                        s[j]=s[j+1];
                                        s[j+1]=temp;
                                }
                }
}
int min(int at[],int n)
{
        int i=0,min=at[i];
        for(i=1;i<n;i++){
                if(min>at[i]){
                        min=at[i];
                }
        }
        return min;
}
int findindex(int at[],int n, int cur)
{
	int j;
	
	for(j=0;j<n;j++){
		if(cur>=at[s[j]] && at[s[j]]!=-1){
				return s[j];
		}
	}
	return -1;
}
void main()
{
        int at[10],at_d[10],bt[10],current,ct[10],bt_d[10],wt[10],tat[10],p[10],p_d[10];

       int n=7,i,k,sum=0;
       float avgwt,avgtat;

        printf("enter the bt \t at\n");
        for(i=0;i<n;i++){
                s[i]=i;
                printf("process: %d\n",i+1);
                printf("bt[%d]: ",i+1);
                scanf("%d",&bt[i]);
                bt_d[i]=bt[i];
                printf("at[%d]: ",i+1);
                scanf("%d",&at[i]);
                at_d[i]=at[i];
                printf("priority[%d]:",i+1);
                scanf("%d",&p[i]);
                p_d[i]=p[i];
        }
        sort(p_d,n);
        for(i=0;i<n;i++)
        	p_d[i]=p[i];
        current=min(at,n);
        while(1){
        	k=findindex(at_d,n,current);
        	if(k==-1)
        		break;
        	current=current+1;
        	bt_d[k]=bt_d[k]-1;
        	if(bt_d[k]==0){
        		ct[k]=current;
        		at_d[k]=-1;
			}
        	
		}
       
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
        printf("avgwt=%f  avgtat=%f\n",avgwt,avgtat);
        printf("ct \t wt\t tat\n");
        for(i=0;i<n;i++)
                        printf("%d\t%d\t%d\n",ct[i],wt[i],tat[i]);

}
