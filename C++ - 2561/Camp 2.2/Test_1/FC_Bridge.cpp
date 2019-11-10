/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[100010],a[100010];
void update(int idx,int v){
    while(idx<=100003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int q,n;
    long long ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ans = 0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=n;i>=1;i--){
            ans+=query(a[i]-1);
            update(a[i],1);
        }
        printf("%lld\n",ans);
        memset(tree,0,sizeof tree);
    }
	return 0;
}
