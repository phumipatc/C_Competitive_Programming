/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,v,id;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A a[500010];
int ans[500010],v[500010],tree[1000010];
void update(int idx,int v){
    while(idx<=1000003){
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
    int n,m,now = 1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&a[i].pos,&a[i].v),a[i].id = i;
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        while(now<=a[i].pos)    update(v[now],1),now++;
        int l = 1,r = 1e6,mid;
        while(l<r){
            mid = (l+r)/2;
            if(query(mid)>=a[i].v)  r = mid;
            else                    l = mid+1;
        }
        ans[a[i].id] = l;
        // printf("%d %d : %d\n",a[i].pos,a[i].v,l);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
	return 0;
}
