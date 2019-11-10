/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    bool operator < (const A&o) const{
        if(u!=o.u)  return u<o.u;
        else        return v<o.v;
    }
};
vector<A > graph;
map<vector<A >,int > mapp;
int main(){
    int t,q,n,u,v;
    scanf("%d %d",&t,&q);
    while(t--){
        scanf("%d",&n);
        n--;
        while(n--){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            graph.push_back({u,v});
        }
        sort(graph.begin(),graph.end());
        mapp[graph]++;
        graph.clear();
    }
    while(q--){
        scanf("%d",&n);
        n--;
        while(n--){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            graph.push_back({u,v});
        }
        sort(graph.begin(),graph.end());
        printf("%d\n",mapp[graph]);
        graph.clear();
    }
	return 0;
}