#include<bits/stdc++.h>
using namespace std;
long long mark[505];
long long ans[505];
int main()
{
    long long n,k,h,cycle,temp,now,v;
    scanf("%lld %lld %lld",&n,&k,&h);
    memset(mark,-1,sizeof mark);
    for(long long i=0;i<n;i++){
        scanf("%lld",&temp);
        temp++;
        for(long long j=1;j<=502;j++){
            if(mark[(i+((j-1)*n))%temp] == i){
				cycle = j-1;
				break;
			}
            mark[(i+((j-1)*n))%temp] = i;
        }
        for(long long j=1;j<=cycle;j++){
            now = (i+((j-1)*n))%temp;
            v = k/cycle;
            if(j<=k%cycle)	v++;
            ans[1]+=v,ans[now+1]-=v;
        }
    }
    for(long long i=1;i<=h;i++){
		ans[i]+=ans[i-1];
		printf("%lld ",ans[i]);
	}
    return 0;
}
