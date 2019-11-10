/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long ,long long> PII;
PII p[100100];
long long c[100100];
int main()
{
    int q,i,n,index,maxx=0;
    scanf("%d",&q);
    while(q--){
        maxx=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%lld %lld",&p[i].first,&p[i].second);
            p[i].first*=(-1);
        }
        sort(p,p+n);
        for(i=0;i<n;i++){
            index=upper_bound(c,c+maxx,p[i].second)-c;
            if(index==maxx)
                maxx++;
            c[index]=p[i].second;
        }
        printf("%d\n",maxx);
    }
    return 0;
}
