/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,st,en,id;
    bool operator < (const A&o) const{
        return x<o.x;
    }
};
A a[80010];
struct B{
    int x,y,id;
    bool operator < (const B&o) const{
        if(x!=o.x)  return x<o.x;
        else        return id<o.id;
    }
};
B b[10010];
int tree[100010],ans[10010];
void upd(int idx,int v){
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
    int n,m,k,x1,y1,x2,y2;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1++,y1++,x2++,y2++;
        a[i].x = x1;
        a[i+n].x = x2+1;
        a[i].st = a[i+n].st = y1;
        a[i].en = a[i+n].en = y2+1;
        a[i].id = 1;
        a[i+n].id = -1;
    }
    for(int i=1;i<=m;i++)
        scanf("%d %d",&b[i].x,&b[i].y),b[i].id = i,b[i].x++,b[i].y++;
    sort(a+1,a+(2*n)+1);
    sort(b+1,b+m+1);
    int now = 1;
    while(now<=m && b[now].x<a[1].x)    now++;
    for(int i=1;i<=(2*n);i++){
        while(now<=m && b[now].x<a[i].x){
            // printf("answering: %d %d %d\n",b[now].x,b[now].y,query(b[now].y));
            ans[b[now].id] = query(b[now].y);
            now++;
        }
        while(a[i].x == a[i+1].x){
            upd(a[i].st,a[i].id);
            upd(a[i].en,-a[i].id);
            i++;
        }
        upd(a[i].st,a[i].id);
        upd(a[i].en,-a[i].id);
        while(now<=m && b[now].x == a[i].x){
            ans[b[now].id] = query(b[now].y);
            now++;
        }
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
	return 0;
}