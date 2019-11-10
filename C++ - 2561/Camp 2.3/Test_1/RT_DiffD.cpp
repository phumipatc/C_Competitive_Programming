/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int ,int > mapp;
int a[100010],tree[400010];
vector<pair<int ,int > > pos;
void build(int l,int r,int now){
    if(l == r){
        tree[now] = pos[l-1].second;
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    tree[now] = min(tree[now*2],tree[(now*2)+1]);
}
int query(int l,int r,int now,int ll,int rr){
    if(l>rr || r<ll)    return 1e9;
    if(ll<=l && rr>=r)  return tree[now];
    int mid = (l+r)/2;
    return min(query(l,mid,now*2,ll,rr),query(mid+1,r,(now*2)+1,ll,rr));
}
int main(){
    int n,q,d,st,en,l,r,ll,rr;
    scanf("%d %d %d",&n,&q,&d);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(mapp[a[i]-d] && mapp[a[i]+d])    pos.push_back({max(mapp[a[i]-d],mapp[a[i]+d]),i});
        else if(mapp[a[i]-d])               pos.push_back({mapp[a[i]-d],i});
        else if(mapp[a[i]+d])               pos.push_back({mapp[a[i]+d],i});
        mapp[a[i]] = i;
    }
    sort(pos.begin(),pos.end());
    build(1,pos.size(),1);
    while(q--){
        scanf("%d %d",&st,&en);
        l = lower_bound(pos.begin(),pos.end(),make_pair(st,0))-pos.begin();
        r = upper_bound(pos.begin(),pos.end(),make_pair(en,0))-pos.begin()-1;
        // printf("%d %d\n%d %d\n",pos[l].first,pos[l].second,pos[r].first,pos[r].second);
        if(query(1,pos.size(),1,l+1,r+1)<=en)   printf("yes\n");
        else                                    printf("no\n");
    }
	return 0;
}
