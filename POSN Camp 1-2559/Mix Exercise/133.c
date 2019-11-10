/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100100];
int main()
{
    int n,q,i,m,r,s,k,j;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&r,&s);
        a[r]++;
        a[s+1]--;
    }
    for(i=1;i<=100000;i++)
        a[i]+=a[i-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d",&k);
        printf("%d\n",a[k]);
    }
return 0;
}
