/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int num[100100];
int main()
{
    int i,j,a,b,c,n,k,sum=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    for(i=n-1;i>=0;i-=k){
        sum+=num[i];
    }
    printf("%d",sum);
    return 0;
}
