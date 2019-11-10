/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int main()
{
    int n,i,m,k,j,ans;
    for(i=0;i<5;i++){
        scanf("%d",&n);
        ans = 0;
        if(n>=1000)     m = 4;
        else if(n>=100) m = 3;
        else if(n>=10)  m = 2;
        else if(n>=1)   m = 1;
        for(int j=n;j!=0;j/=10,m--){
            k = j%10;
            ans+=pow(k,m);
        }
        if(ans == n)    printf("Y");
        else            printf("N");
    }
    return 0;
}
