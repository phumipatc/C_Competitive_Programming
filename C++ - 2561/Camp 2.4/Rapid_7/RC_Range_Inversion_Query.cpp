/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,id;
    bool operator < (const A&o) const{
        return r<o.r;
    }
};
vector<A > Q[230];
int a[50010],b[50010],c[50010];
long long ans[50010],tree[50010];
void update(int idx,int v){
    while(idx<=50000){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
long long query(int idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,q,sq,l,r,countt = 1,idx;
    scanf("%d %d",&n,&q);
    sq = sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i] = a[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        c[i] = lower_bound(b+1,b+n+1,a[i])-b;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        Q[l/sq].push_back({l,r,i});
    }
    long long sum;
    for(int i=0;i<=sq;i++){
        if(Q[i].empty())    continue;
        sort(Q[i].begin(),Q[i].end());
        l = Q[i][0].l,r = Q[i][0].l,sum = 0;
        for(auto x:Q[i]){
            while(r<=x.r){
                idx = c[r];
                sum+=query(50000)-query(idx);
                update(idx,1);
                r++;
            }
            if(l<=x.l){
                while(l<x.l){
                    idx = c[l];
                    sum-=query(idx-1);
                    update(idx,-1);
                    l++;
                }
            }else{
                l--;
                while(l>=x.l){
                    idx = c[l];
                    sum+=query(idx-1);
                    update(idx,1);
                    l--;
                }
                l++;
            }
            ans[x.id] = sum;
        }
        memset(tree,0,sizeof tree);
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
	return 0;
}
