/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b){
    if(a<=b){
        if(b%a==0){
            return a;
        }else{
            return gcd(a,b%a);
        }
    }else{
        if(a%b==0){
            return b;
        }else{
            return gcd(a%b,b);
        }
    }
}
int main()
{
    int n,i,j,q,count=0,G,a[50];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        for(j=1;j<=a[i];j++){
            G=gcd(j,a[i]);
            if(G==1){
                count++;
            }
        }
        printf("%d",count);
        count=0;
    }
    return 0;
}
