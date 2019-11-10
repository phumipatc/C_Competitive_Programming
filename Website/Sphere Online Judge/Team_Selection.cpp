/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,a,b,c;
    bool operator < (const A&o) const{
        return a<o.a;
    }
};
A order[500100];
int tree[2000100];
void update(int l,int r,int now,int idx,int v){
    if(r<idx || l>idx)    return ;
    if(l == r && l == idx){
        tree[now]+=v;
        return ;
    }
    int mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,(now*2)+1,idx,v);
    tree[now] = min(tree[now*2],tree[(now*2)+1]);
}
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        order[num].a = i;
        order[num].id = num;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        order[num].b = i;
        order[num].id = num;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        order[num].c = i;
        order[num].id = num;
    }
    sort(order+1,order+n+1);
    for(int i=1;i<=n;i++){
        update(1,n,1,order[i].b,order[i].c);
    }
    return 0;
}
