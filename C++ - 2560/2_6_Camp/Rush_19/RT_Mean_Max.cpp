/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
double a[300005],qs[300005];
int main(){
    int n,k;
    double ans = 0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
        qs[i] = a[i]+qs[i-1];
    }
    for(int i=0;i<=n-k;i++)
        for(int j=i+k;j<=n;j++)
            ans = max(ans,(qs[j]-qs[i])/(j-i));
    printf("%.1lf\n",ans);
    return 0;
}
