/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int fibo[200]={0,1,2,3};
int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=4;i<=100;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%10000019;
    }
    for(i=0;i<n;i++){
        scanf("%d",&num);
        printf("%d\n",fibo[num]);
    }
return 0;
}
