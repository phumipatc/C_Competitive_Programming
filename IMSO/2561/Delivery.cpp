/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
vector<int > g[135000];
pair<int,int > p[6];
int dis[6][135000];
int main(){
    int k,l,q,u,v;
    scanf("%d %d %d",&k,&l,&q);
    for(int i=1;i<(1<<k);i++){
        if(i*2+1<(1<<k)){
            g[i].push_back(i*2);
            g[i].push_back(i*2+1);
        }
        if(i!=1)    g[i].push_back(i/2);
    }
    for(int i=1;i<(1<<k);i++){
        if(i*2+1<(1<<k)){
            g[i+(1<<k)].push_back(i*2+(1<<k));
            g[i+(1<<k)].push_back(i*2+1+(1<<k));
        }
        if(i!=1)    g[i+(1<<k)].push_back(i/2+(1<<k));
    }
    for(int i=1;i<=l;i++){
        scanf("%d %d",&p[i].first,&p[i].second);
        g[p[i].first].push_back(p[i].second);
        g[p[i].second].push_back(p[i].first);
        for(int j=1;j<(1<<(k+1));j++)
            dis[i][j] = 1e9;
        dis[i][p[i].first] = 0;
    }
    for(int i=1;i<=l;i++){
        heap.push({p[i].first,0});
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            for(auto &x:g[now.v]){
                if(dis[i][x]>now.w+1){
                    dis[i][x] = now.w+1;
                    heap.push({x,now.w+1});
                }
            }
        }
    }
    int ans,countt;
    while(q--){
        scanf("%d %d",&u,&v);
        ans = 1e9,countt = 0;
        for(int i=1;i<=l;i++)
            ans = min(ans,dis[i][u]+dis[i][v]);
        if(u<(1<<k) && v<(1<<k)){
            while(u!=v){
                if(u>v) u/=2;
                else    v/=2;
                countt++;
            }
            ans = min(ans,countt);
        }else if(u>(1<<k) && v>(1<<k)){
            while(u!=v){
                if(u>v) u = ((u-(1<<k))/2)+(1<<k);
                else    v = ((v-(1<<k))/2)+(1<<k);
                countt++;
            }
            ans = min(ans,countt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
