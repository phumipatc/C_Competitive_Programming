/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
A now;
priority_queue<A > heap;
int p[2510];
int find_root(int i){
    if(p[i] == i)   return i;
    else            return p[i] = find_root(p[i]);
}
int main(){
    int n,m,st,en,num,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&now.u,&now.v,&now.w);
        heap.push(now);
    }
    scanf("%d %d %d",&st,&en,&num);
    for(int i=1;i<=n;i++)   p[i] = i;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = find_root(now.u);
        rv = find_root(now.v);
        if(ru == rv)    continue;
        p[ru] = rv;
        ru = find_root(st);
        rv = find_root(en);
        if(ru == rv){
            printf("%d\n",(int)ceil((double)num/(now.w-1)));
            break;
        }
    }
	return 0;
}
