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
        return w<o.w;
    }
};
A now;
priority_queue< A> heap;
map<int,int> mapp;
int p[50100];
int find_root(int n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int ru,rv,q,num,m,n,u,v,w,all,ans;
    scanf("%d",&q);
    while(q--){
        all = ans = 0;
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++){
            scanf("%d",&num);
            mapp[num] = i;
            p[i] = i;
        }
        while(n--){
            scanf("%d %d %d",&u,&v,&w);
            all+=w;
            heap.push({mapp[u],mapp[v],w});
        }
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            ru = find_root(now.u);
            rv = find_root(now.v);
            if(ru == rv)    continue;
            p[ru] = rv;
            ans+=now.w;
        }
        printf("%d\n",all-ans);
        mapp.clear();
    }
	return 0;
}
