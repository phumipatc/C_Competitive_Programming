#include<stdio.h>
int a[40];
int main(){
    int n,i=0;
    scanf("%d",&n);
    while(n>1){
        a[i++]=n%2;
        n/=2;
    }
    a[i]=1;
    for(i=31;i>=0;i--){
        printf("%d",a[i]);
        if(i%4==0)
            printf(" ");
    }
    return 0;
}
