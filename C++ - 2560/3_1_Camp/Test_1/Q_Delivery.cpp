/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
A p[6],now;
queue<A > que;
vector< int> g[142000];
int dis[6][142000];
int main(){
    int u,v,k,l,q,a,b,ans,countt,ta,tb;
    scanf("%d %d %d",&k,&l,&q);
    for(int i=1;i<(1<<k);i++){
        if((i*2)+1<(1<<k)){
            g[i].push_back(i*2);
            g[i].push_back((i*2)+1);
        }
        if(i!=1)    g[i].push_back(i/2);
    }
    for(int i=1+(1<<k);i<(1<<k)+(1<<k);i++){
        if(((i-(1<<k))*2)+1<(1<<k)){
            g[i].push_back(((i-(1<<k))*2)+(1<<k));
            g[i].push_back(((i-(1<<k))*2)+1+(1<<k));
        }
        if(i!=1+(1<<k)) g[i].push_back(((i-(1<<k))/2)+(1<<k));
    }
    for(int i=1;i<=l;i++){
        scanf("%d %d",&p[i].u,&p[i].v);
        g[p[i].u].push_back(p[i].v);
        g[p[i].v].push_back(p[i].u);
    }
//    for(int i=1;i<=(1<<k)+(1<<k);i++){
//        cout << i << ':';
//        for(auto &j:g[i])
//            cout << j << ' ';
//        cout << endl;
//    }
    for(int i=1;i<=l;i++){
        for(int j=1;j<(1<<k)+(1<<k);j++){
            dis[i][j] = 1e9;
        }
    }
    for(int i=1;i<=l;i++){
        que.push({p[i].u,0});
        dis[i][p[i].u] = 0;
        while(!que.empty()){
            now = que.front();
            que.pop();
            for(auto &x:g[now.u]){
                if(dis[i][x]>now.v+1){
                    dis[i][x] = now.v+1;
                    que.push({x,now.v+1});
                }
            }
        }
    }
//    for(int i=1;i<=l;i++){
//        for(int j=1;j<(1<<k)+(1<<k);j++){
//            cout << dis[i][j] << ' ';
//        }
//        cout << endl;
//    }
    while(q--){
        scanf("%d %d",&a,&b);
        ans = 1e9,countt = 0;
        for(int i=1;i<=l;i++)
            ans = min(ans,dis[i][a]+dis[i][b]);
        if(a<(1<<k) && b<(1<<k)){
            ta = a,tb = b;
            while(ta!=tb){
                if(ta>tb)   ta/=2;
                else        tb/=2;
                countt++;
            }
            ans = min(ans,countt);
        }else if(a>(1<<k) && b>(1<<k)){
            ta = a,tb = b;
            while(ta!=tb){
                if(ta>tb)   ta = ((ta-(1<<k))/2)+(1<<k);
                else        tb = ((tb-(1<<k))/2)+(1<<k);
                countt++;
            }
            ans = min(ans,countt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
