/*
    TASK: AP_Bar Chart
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],l[100100],r[100100];
int main()
{
	long long q,i,ans,n;
	scanf("%lld",&q);
	while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(i=1;i<=n;i++){
            l[i]=i-1;
            while(l[i]>0 && a[i]<=a[l[i]])
                l[i] = l[l[i]];
        }
        for(i=n;i>=1;i--){
            r[i]=i+1;
            while(r[i]<=n && a[i]<=a[r[i]])
                r[i] = r[r[i]];
        }
        ans=0;
        for(i=1;i<=n;i++)
            ans=max(ans,(r[i]-l[i]-1)*a[i]);
        printf("%lld\n",ans);
        memset(a,0,sizeof a);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
	}
    return 0;
}
/*
2 6 2 1 5 6 2 3 3 100 100 100
*/
