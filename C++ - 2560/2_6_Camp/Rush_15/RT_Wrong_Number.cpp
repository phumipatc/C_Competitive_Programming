/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,loop,sum,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        loop = num%10;
        num/=10;
        sum = 1;
        for(int j=1;j<=loop;j++)
            sum*=num;
        ans+=sum;
    }
    printf("%d\n",ans);
    return 0;
}
