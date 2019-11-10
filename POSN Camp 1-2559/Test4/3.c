/*
    TASK: Valley of the kings
    AUTHOR: Phumipat
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[2000];
int main()
{
    int n,i,j,p,q,x,y,z,score=0,k,l,ch;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&p);
        for(j=0;j<p;j++)
                scanf("%d",&a[j]);
        for(j=0;j<p;j++){
            for(k=j+1;k<p;k++)
            if(a[j]!=0){
            if(a[j]==a[k]){
                a[j]=0;
                a[k]=0;
                score++;
            }
        }
        }
        printf("%d\n",score);
        score=0;
        for(j=0;j<p;j++){
            for(k=0;k<p;k++){
            if(a[j]<a[k]){
                q=a[j];
                a[j]=a[k];
                a[k]=q;
            }

        }

        }for(l=0;l<p;l++){
            ch=1;
            if(a[l]!=0){
                printf("%d ",a[l]);
                ch=0;

            }


        }
        if(ch!=0){
                printf("Empty");
        }else{
        }
    }
    return 0;
}

