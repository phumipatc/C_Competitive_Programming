#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
PI a[100100];
int main(){
    int n,m,i;
    long long ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    sort(a,a+n);
    for(i=1;i<n;i++)
        if(a[i-1].second>a[i].second)
            ans+=(a[i-1].second-a[i].second);
    printf("%lld\n",ans+a[n-1].second);
    return 0;
}
