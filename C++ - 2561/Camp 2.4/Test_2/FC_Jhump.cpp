/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
A a[100010];
set<int > sett;
vector<int > g[100010];
queue<int > que;
int comp[100010],mark[100010];
int main(){
    int q,n,u,v,countt,ans;
    scanf("%d",&q);
    for(int qq=1;qq<=q;qq++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&u,&v);
            sett.insert(u);
            sett.insert(v);
            a[i] = {u,v};
        }
        countt = 1;
        for(auto x:sett)
            comp[countt++] = x;
        for(int i=1;i<=n;i++){
            if(a[i].u<a[i].v)   continue;
            u = lower_bound(comp+1,comp+countt,a[i].u)-comp;
            v = lower_bound(comp+1,comp+countt,a[i].v)-comp;
            g[u].push_back(v);
        }
        countt--,ans = 0;
        for(int i=countt;i>=1;i--){
            if(mark[i]) continue;
            mark[i] = 1;
            que.push(i);
            ans++;
            while(!que.empty()){
                int now = que.front(),num = 0;
                que.pop();
                for(auto x:g[now]){
                    if(mark[x]) continue;
                    num++;
                    mark[x] = 1;
                    que.push(x);
                }
                // printf("%d %d\n",now,num);
                ans+=max(num-1,0);
            }
        }
        printf("Case #%d: %d\n",qq,ans);
        sett.clear();
        for(int i=1;i<=countt;i++)
            g[i].clear();
        memset(mark,0,sizeof mark);
    }
	return 0;
}
