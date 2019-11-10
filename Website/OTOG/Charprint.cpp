/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[300010],b[100010];
long long tree[30][300010];
void update(long long c,long long idx,long long v){
    while(idx<=300003){
        tree[c][idx]+=v;
        idx+=idx & -idx;
    }
}
long long query(long long c,long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[c][idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long t,lena,lenb;
    scanf("%lld %s %s",&t,a+1,b+1);
    lena = strlen(a+1);
    lenb = strlen(b+1);
    for(long long i=1;i<=lena;i++){
        update(0,i,1);
        update(a[i]-'a'+1,i,1);
    }
    long long ans = 0,l,r,mid;
    for(long long i=1;i<=lenb;i++){
        l = 1,r = lena+1;
        while(l<r){
            mid = (l+r)/2;
            if(query(b[i]-'a'+1,mid) == 0)  l = mid+1;
            else                            r = mid;
        }
        if(l == lena+1){
            printf("-1\n");
            return 0;
        }
        ans+=query(0,l);
        // printf("%lld %lld %lld\n",i,l,ans);
        if(t == 1)  update(0,l,-1);
        update(b[i]-'a'+1,l,-1);
    }
    printf("%lld\n",ans);
	return 0;
}