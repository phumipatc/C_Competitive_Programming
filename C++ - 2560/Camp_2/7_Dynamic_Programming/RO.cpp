/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
long long mic[1000100],b[1000100];
PII a[1000100];
int main()
{
    long long n,k,i,idx,ans=-1;
    char ch;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++){
        scanf(" %c",&ch);
        if(ch=='O')         mic[i]=mic[i-1]+1;
        else if(ch=='R')    mic[i]=mic[i-1]-k;
        a[i].first=mic[i],a[i].second=i;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
        b[i]=a[i].first;
    for(i=1;i<n;i++){
        if(a[i].first==a[i+1].first){
            idx=upper_bound(b,b+n+1,b[i])-(b);
            ans=max(ans,a[idx-1].second-a[i].second);
            i=idx-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
15 3
RORROOROOROOORO

17 3
OROOOOOROOOOORRRR
*/
