/*
    TASK: Army
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[210000];
int main()
{
    int i,j,n,sum=0,max=-2000000000,start=0,end,startjing=0,ch=1,old,len=0;
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
                len=end-startjing+1;
               // printf("%d %d %d\n",max,len,startjing);
            }
            else if(sum==max){
                    if(i-start+1>len){

                        len=i-start+1;
                        startjing=start;
                        end=i;
                    }
            }
        }
            }printf("%d\n",max);
        for(i=startjing;i<=end;i++)
            printf("%d ",a[i]);
        printf("\n");


    }else{
       //printf("%d\n",max);
        for(i=0;i<n;i++){
            if(a[i]>max){
                max=a[i];
                old=i;
            }
        }
        printf("%d\n",max);
        printf("%d",max);
    }








            return 0;
}

