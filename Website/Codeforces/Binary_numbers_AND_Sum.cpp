/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
char a[200010],b[200010];
long long tree[200010];
long long pre[200010];
void update(long long idx,long long v){
    while(idx<=200003){
        tree[idx]+=v;
        idx+=idx & -idx;
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx & -idx;
    }
    return sum;
}
int main(){
    long long n,m,sum = 0;
    scanf("%lld %lld %s %s",&n,&m,a+1,b+1);
    pre[0] = 1;
    for(long long i=1;i<=200000;i++)
        pre[i] = (pre[i-1]*2)%MOD;
    for(long long i=m;i>=1;i--){
        if(b[i] == '0') continue;
        update(m-i+1,1);
    }
    for(long long i=n;i>=1;i--){
        if(a[i] == '0') continue;
        sum = (sum+(pre[n-i]*(query(m)-query(n-i)))%MOD)%MOD;
        // printf("%lld %lld %lld\n",pre[n-i],query(m)-query(i-1),sum);
    }
    printf("%lld\n",sum);
	return 0;
}