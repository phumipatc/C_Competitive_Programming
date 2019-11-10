/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator< (const A&o) const{
        return w<o.w;
    }
};
A a[5000100];
int p[4100];
int len[4100];
int find_root(int n){
    if(p[n]==n) return n;
    else        return p[n]=find_root(p[n]);
}
int main(){
    int n,m,q,u,v,w,idx = 0,ra,rb;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++)   p[i] = i;
    for(int i=1;i<=m;i++){
        ra = find_root(a[i].u);
        rb = find_root(a[i].v);
        if(ra!=rb){
            p[rb] = ra;
            len[idx++] = a[i].w;
        }
    }
    while(q--){
        int k;
        scanf("%d",&k);
        int att = upper_bound(len,len+idx,k)-len;
        printf("%d\n",n-att);
    }
    return 0;
}
/*
5 6 2
1 2 7
1 3 7
1 4 7
2 5 4
3 5 3
4 5 5
5
7
*/
