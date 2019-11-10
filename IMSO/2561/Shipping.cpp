/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int now,state;
};
A temp;
vector<int> g[100100],level[100100];
int a[100100],mark[100100],maxlv = 0;
queue< A> que;
int main(){
    int q,n,u,v,st,ans;
    scanf("%d",&q);
    while(q--){
        ans = -1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(g[i].size() == 1){
                st = i;
                break;
            }
        }
        que.push({st,1});
        mark[st] = 1;
        level[1].push_back(st);
        while(!que.empty()){
            temp = que.front();
            que.pop();
            maxlv = max(maxlv,temp.state);
            for(auto &x:g[temp.now]){
                if(!mark[x]){
                    mark[x] = 1;
                    level[temp.state+1].push_back(x);
                    que.push({x,temp.state+1});
                }
            }
        }
        for(int i=1;i<=maxlv-4;i++){
            if(!level[i].size())    continue;
            if(!level[i+4].size())  continue;
            for(auto &x:level[i]){
                for(auto &y:level[i+4]){
                    ans = max(ans,a[x]+a[y]);
                }
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++){
            g[i].clear();
            level[i].clear();
        }
    }
    return 0;
}
