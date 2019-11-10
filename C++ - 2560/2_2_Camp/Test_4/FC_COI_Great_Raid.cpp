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
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue< A> heap;
int p[100100],value[100100];
int find_root(int n){
    if(p[n]==n) return n;
    else        return p[n]=find_root(p[n]);
}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]),p[i]=i;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        heap.push({a,b,value[a]+value[b]});
    }
    int ans=0;
    while(!heap.empty()){
        A now=heap.top();
        heap.pop();
        int ra=find_root(now.u);
        int rb=find_root(now.v);
        if(ra!=rb){
            ans+=now.w;
            p[ra]=rb;
        }
    }
    printf("%d\n",ans);
    return 0;
}
