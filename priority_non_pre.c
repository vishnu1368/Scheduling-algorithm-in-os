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
        for(i=0;i<n;i++)
                printf("%d\n",s[i]);
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

void main()
{
        int at[10],bt[10],current,ct[10],p_d[10],wt[10],tat[10],p[10];

       int n=7,i,k,sum=0;
       float avgwt,avgtat;

        printf("enter the bt \t at\n");
        for(i=0;i<n;i++){
                s[i]=i;
                printf("process: %d\n",i+1);
                printf("bt[%d]: ",i+1);
                scanf("%d",&bt[i]);
                printf("p[%d]: ",i+1);
                scanf("%d",&p[i]);
                p_d[i]=p[i];
                printf("at[%d]: ",i+1);
                scanf("%d",&at[i]);
        }
        sort(p_d,n);
        current=min(at,n);
        for(i=0;i<n;i++){
                for(k=0;k<n;k++){
                        if(at[s[k]]>current || s[k]==-1){
                                continue;
                        }
                        if(at[s[k]]<=current){
                                current=bt[s[k]]+current;
                                ct[s[k]]=current;
                                s[k]=-1;
                        }

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
