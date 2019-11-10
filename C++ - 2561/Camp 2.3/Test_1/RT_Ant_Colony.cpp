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
};
struct B{
    int idx,weight,level;
};
vector< A> g[100005];
queue< B> que;
int lv[100005],qs[100005],ta,tb;
void diflv(){
    while(lv[ta]>lv[tb]){
            for(int i=0;i<g[ta].size();i++){
                if(lv[g[ta][i].v]<lv[ta]){
                    ta = g[ta][i].v;
                    break;
                }
            }
        }
        while(lv[tb]>lv[ta]){
            for(int i=0;i<g[tb].size();i++){
                if(lv[g[tb][i].v]<lv[tb]){
                    tb = g[tb][i].v;
                    break;
                }
            }
        }
}
int main(){
    int n,q,u,v,w,a,b;
    scanf("%d %d",&n,&q);
    for(int i=1;i<n;i++){
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    que.push({0,0,1});
    lv[0] = 1;
    while(!que.empty()){
        B now=que.front();
        que.pop();
        for(int i=0;i<g[now.idx].size();i++){
            if(lv[g[now.idx][i].v])   continue;
            lv[g[now.idx][i].v] = now.level+1;
            qs[g[now.idx][i].v] = now.weight+g[now.idx][i].w;
            que.push({g[now.idx][i].v,now.weight+g[now.idx][i].w,now.level+1});
        }
    }
    while(q--){
        scanf("%d %d",&a,&b);
        ta = a,tb = b;
        diflv();
        while(ta!=tb){
            for(int i=0;i<g[ta].size();i++){
                if(lv[g[ta][i].v]<lv[ta]){
                    ta = g[ta][i].v;
                    break;
                }
            }
            for(int i=0;i<g[tb].size();i++){
                if(lv[g[tb][i].v]<lv[tb]){
                    tb = g[tb][i].v;
                    break;
                }
            }
        }
        printf("%d\n",qs[a]+qs[b]-(2*qs[ta]));
    }
    return 0;
}
