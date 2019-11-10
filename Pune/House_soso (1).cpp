#include<bits/stdc++.h>
#define Min 1e9
using namespace std;
struct A{
    int qs,l,r,ans;
};
A seg[800100];
int cou[200100];
void build(int l,int r,int now,int want,int co){

    if(l>want||r<want)  return ;
    if(l == want &&  r== want){
        seg[now].qs = co;
        seg[now].l = min(0,co);
        seg[now].r = min(0,co);
        seg[now].ans = co;
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,now*2,want,co);
    build(mid+1,r,now*2+1,want,co);
    seg[now].qs = seg[now*2].qs + seg[now*2+1].qs;
    seg[now].l = min(seg[now*2].l,seg[now*2].qs + seg[now*2+1].l);
    seg[now].r = min(seg[now*2+1].r,seg[now*2].r + seg[now*2+1].qs);
    seg[now].ans = max(seg[now].ans,max(seg[now*2+1].ans,seg[now].qs - seg[now*2].l - seg[now*2+1].r));
}
A query(int l,int r,int now,int ll,int rr){
    //printf("%d %d %d\n",l,r,now);
    if(r < ll || rr < l){
        return {Min,Min,Min,Min};
    }
    if(ll <= l && r <= rr){
        return seg[now];
    }
    int mid = (l+r)/2;
    A a,b;
    int c,d,e,f;
    a = query(l,mid,now*2,ll,rr);
    b = query(mid+1,r,now*2+1,ll,rr);
    if(a.ans==Min)
    {
        return b;
    }
    if(b.ans==Min)
    {
        return a;
    }
    f=max(a.ans,max(b.ans,(a.qs+b.qs)-(a.l+b.r)));
    c=a.qs+b.qs;
    d=min(a.l,a.qs + b.l);
    e=min(b.r,b.qs + a.r);
    return {c,d,e,f};
}
int main()
{
    int n,q,i,j,x,y;
    A tmp;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        scanf("%d",&cou[i]);
        build(1,n,1,i,cou[i]);
    }
    while(q--){
        scanf("%d %d",&x,&y);
        x++;
        y++;
        tmp=query(1,n,1,x,y);
        printf("%d\n",max(0,tmp.ans));
    }
    return 0;
}
/*

*/
