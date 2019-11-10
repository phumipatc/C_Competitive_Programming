/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,ans1=1e9,ans2;
    scanf("%d %d",&n,&a);
    int en=n*a;
    for(int i=1;i<=en;i++)
        if(i/n==i-a)
            ans1=min(ans1,i),ans2=i;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
