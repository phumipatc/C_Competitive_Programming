/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[25];
long long tree[25][300010],a[300010];
void update(long long idx,long long pos,long long v){
    while(idx<=300003){
        tree[pos][idx]+=v;
        idx+= idx & -idx;
    }
}
long long query(long long idx,long long pos){
    long long sum = 0;
    while(idx>0){
        sum+=tree[pos][idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long n,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf(" %s",str);
        a[i] = strlen(str);
        update(i,a[i],1);
    }
    long long ans = 0;
    for(long long i=1;i<=n;i++)
        ans+=query(min(n,i+k),a[i])-query(i,a[i]);
    printf("%lld\n",ans);
	return 0;
}
