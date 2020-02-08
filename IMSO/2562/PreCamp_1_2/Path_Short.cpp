/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
};
vector<A > v;
struct B{
    long long v,w;
    bool operator < (const B&o) const{
        return w>o.w;
    }
};
priority_queue<B > heap;
vector<B > g[310],gg[310];
long long dis[310];
long long check(A now){
    for(long long i=0;i<v.size();i++){
        if(v[i].x!=now.x || v[i].y!=now.y)    continue;
        return i;
    }
    return -1;
}
long long getdis(A p1,A p2){
    long long dx = abs(p1.x-p2.x),dy = abs(p1.y-p2.y);
    if(dx == dy || dx>dy)   return dx;
    if(dx<dy){
        if((dy-dx)%2)   return dy+1;
        else            return dy;
    }
}
int main(){
    A p1,p2;
    B now;
    long long m,q,st,en;
    scanf("%lld %lld",&m,&q);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld %lld %lld",&p1.x,&p1.y,&p2.x,&p2.y);
        if(check(p1)!=-1)   st = check(p1);
        else{
            v.push_back(p1);
            st = v.size()-1;
        }
        if(check(p2)!=-1)   en = check(p2);
        else{
            v.push_back(p2);
            en = v.size()-1;
        }
        g[st].push_back({en,1});
        g[en].push_back({st,1});
    }
    for(long long i=0;i<v.size();i++){
        for(long long j=i+1;j<v.size();j++){
            g[i].push_back({j,getdis(v[i],v[j])});
            g[j].push_back({i,getdis(v[i],v[j])});
        }
    }
    while(q--){
        scanf("%lld %lld %lld %lld",&p1.x,&p1.y,&p2.x,&p2.y);
        for(long long i=0;i<=300;i++) gg[i].clear();
        fill(dis,dis+300,1e9);
        for(long long i=0;i<=200;i++)
            for(auto j:g[i])
                gg[i].push_back(j);
        if(check(p1)!=-1)   st = check(p1);
        else{
            st = v.size()+1;
            for(long long i=0;i<v.size();i++){
                gg[st].push_back({i,getdis(p1,v[i])});
                gg[i].push_back({st,getdis(p1,v[i])});
            }
        }
        if(check(p2)!=-1)   en = check(p2);
        else{
            en = v.size()+2;
            for(long long i=0;i<v.size();i++){
                gg[en].push_back({i,getdis(p2,v[i])});
                gg[i].push_back({en,getdis(p2,v[i])});
            }
        }
        gg[st].push_back({en,getdis(p1,p2)});
        gg[en].push_back({st,getdis(p1,p2)});
        dis[st] = 0;
        heap.push({st,0});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            for(auto x:gg[now.v]){
                if(dis[x.v]<=now.w+x.w) continue;
                dis[x.v] = now.w+x.w;
                heap.push({x.v,dis[x.v]});
            }
        }
        printf("%lld\n",dis[en]);
    }
	return 0;
}