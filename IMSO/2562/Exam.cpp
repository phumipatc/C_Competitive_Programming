/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include <bits/stdc++.h>
using namespace std;
struct A{
    int l,r,num;
    bool operator < (const A&o) const{
        return r<o.r;
    }
};
A q[500010];
vector<A > cluster[50010];
vector<int > v;
map<int ,int > mapp;
int a[50010],tree[50010],temp[50010],ans[500010];
void upd(int idx,int v){
    while(idx<=50003){
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
int main() {
    int n,m,sq;
	scanf("%d", &n);
    sq = sqrt(n);
	for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),v.emplace_back(a[i]);
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=0;i<v.size();i++)
        mapp[v[i]] = i+1;
	scanf("%d", &m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l++,q[i].r++;
        q[i].num = i;
        cluster[q[i].l/sq].push_back(q[i]);
    }
    sort(q+1,q+m+1);
    for(int i=0;i<=sq;i++)
        sort(cluster[i].begin(),cluster[i].end());
    memset(temp,-1,sizeof temp);
    int now = 1;
    for(int i=1;i<=n;i++){
        if(temp[mapp[a[i]]]!=-1)
            upd(temp[mapp[a[i]]],-1);
        temp[mapp[a[i]]] = i;
        upd(i,1);
        while(now<=m && q[now].r == i){
            ans[q[now].num] = (q[now].r-q[now].l+1)-(query(q[now].r)-query(q[now].l-1));
            // printf("%d %d %d\n",now,query(q[now].r),query(q[now].l));
            now++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
}
/*
9
9 138 2 2 3 7 19 9 11
*/