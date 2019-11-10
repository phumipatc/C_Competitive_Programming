/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[210000];
int main()
{
    int i,j,n,sum=0,max=-2000000000,start=0,end,startjing=0,ch=1,old;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        if(a[i]>=0){
            ch=0;
        }
    }
    if(ch==0){
    for(i=0;i<n;i++){
        sum+=a[i];
        if(sum<0){
           sum=0;
            start=i+1;
        }else{
            if(sum>max){
                max=sum;
                startjing=start;
                end=i;
            }
        }
            }printf("%d %d",startjing+1,end+1);
        printf("\n");
        printf("%d\n",max);
    }else{
        for(i=0;i<n;i++){
            if(a[i]>max){
                max=a[i];
                old=i;
            }
        }
        printf("%d %d\n",old+1,old+1);
        printf("%d",max);
    }
            return 0;
}

