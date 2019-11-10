#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double a[1000000];
/*
int cmp(const void *a,const void *b){
    if(*(double *)a > *(double *)b){
        return 1;
    }else{
        return -1;
    }
}
*/
int main()
{
    int x,i,j;
    double sum=0,min=10000000,max=-1000000,old;
    printf("Enter times :");
    scanf("%d",&x);
        for(i=0;i<x;i++){
            printf("Enter Number %d :",i+1);
            scanf("%lf",&a[i]);
            sum+=a[i];
            if(min>a[i])
                min=a[i];
            if(max<a[i])
                max=a[i];
        }
        //qsort(a,x,sizeof(double),cmp);
        printf("sum = %.2lf\nmin = %.2lf\nmax = %.2lf\nAvg = %.2lf\n",sum,min,max,sum/x);
        /*
        printf("\nAscending = ");
        for(i=0;i<x;i++)
            printf("%.2lf ",a[i]);
        printf("\nDescending = ");
        for(i=x-1;i>=0;i--)
            printf("%.2lf ",a[i]);
        */
        for(i=0;i<x-1;i++){
            for(j=0;j<x;j++){
                if(a[j]<a[j+1]){
                    old=a[j];
                    a[j]=a[j+1];
                    a[j+1]=old;
                }
            }
        }

        printf("Ascending = ");
        for(i=x-1;i>=0;i--)
            printf("%.2lf ",a[i]);
        printf("\n");

        printf("Descending = ");
        for(i=0;i<x;i++)
            printf("%.2lf ",a[i]);
            printf("\n");
return 0;
}
