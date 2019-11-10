/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long x[100100],y[100100],p[100100][2];
int main(){
    long long n,i,ans=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&p[i][0],&p[i][1]);
        x[p[i][0]]++;
        y[p[i][1]]++;
    }
    for(i=0;i<n;i++)
        ans+=(x[p[i][0]]-1)*(y[p[i][1]]-1);
    printf("%lld\n",ans);
return 0;
}
