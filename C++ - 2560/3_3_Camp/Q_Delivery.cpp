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
A now;
vector<int> g[132000];
pair<int,int> p[6];
queue< A> que;
int dis[6][132000];
int main(){
    int k,l,q,a,b;
    cin >> k >> l >> q;
    for(int i=1;i<(1<<k);i++){
        if((2*i)+1>=(1<<k)) continue;
        g[i].push_back(2*i);
        g[i].push_back((2*i)+1);
        g[2*i].push_back(i);
        g[(2*i)+1].push_back(i);
    }
    for(int i=(1<<k)+1;i<2*(1<<k);i++){
        if(2*(i-(1<<k))+1+(1<<k)>=2*(1<<k)) continue;
        g[i].push_back(2*(i-(1<<k))+(1<<k));
        g[i].push_back(2*(i-(1<<k))+1+(1<<k));
        g[2*(i-(1<<k))+(1<<k)].push_back(i);
        g[2*(i-(1<<k))+1+(1<<k)].push_back(i);
    }
    for(int i=1;i<=l;i++){
        cin >> p[i].first >> p[i].second;
        g[p[i].first].push_back(p[i].second);
        g[p[i].second].push_back(p[i].first);
    }
    for(int i=1;i<=l;i++){
        que.push({p[i].first,0});
        for(int j=1;j<2*(1<<k);j++)
            dis[i][j] = 1e9;
        dis[i][p[i].first] = 0;
        while(!que.empty()){
            now = que.front();
            que.pop();
            for(int j=0;j<g[now.v].size();j++){
                if(dis[i][g[now.v][j]]>now.w+1){
                    dis[i][g[now.v][j]] = now.w+1;
                    que.push({g[now.v][j],now.w+1});
                }
            }
        }
    }
    while(q--){
        cin >> a >> b;
        int countt = 0,ans = 1e9;
        for(int i=1;i<=l;i++)
            ans = min(ans,dis[i][a]+dis[i][b]);
        if(a<(1<<k) && b<(1<<k)){
            while(a!=b){
                if(a>b) a/=2;
                else    b/=2;
                countt++;
            }
            ans = min(ans,countt);
        }else if(a>(1<<k) && b>(1<<k)){
            while(a!=b){
                if(a>b) a = ((a-(1<<k))/2)+(1<<k);
                else    b = ((b-(1<<k))/2)+(1<<k);
                countt++;
            }
            ans = min(ans,countt);
        }
        cout << ans << endl;
    }
    return 0;
}
