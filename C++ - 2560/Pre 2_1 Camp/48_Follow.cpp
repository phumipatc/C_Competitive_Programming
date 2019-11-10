/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,w;
    bool operator < (const A& o) const{
        return w>o.w;
    }
};
A tmp;
priority_queue<A> dijk;
long long dis[1010][1010],stp[1010][1010],enp[1010][1010],mark[1010][1010],ans[1010];
int peat[1010];
vector<int> g[1010];
int main(){
    int q,n,m,s,e,t,p,i,next,u,noww,j,a,b,d;
    long long sum,tim;
    scanf(" %d",&q);
    while(q--){
        memset(mark,0,sizeof mark);
        scanf(" %d %d",&n,&m);
        scanf(" %d %d %d %d",&s,&e,&t,&p);
        scanf(" %d",&peat[0]);
        for(i=1;i<p;i++) scanf(" %d",&peat[i]),mark[peat[i]][peat[i-1]]=mark[peat[i-1]][peat[i]]=1;
        for(i=1;i<=n;i++){
            ans[i]=1<<30;
            for(j=1;j<=n;j++){
                if(i==j) dis[i][j]=0;
                else dis[i][j]=1<<30;
            }
        }
        for(i=0;i<m;i++){
            scanf(" %d %d %d",&a,&b,&d);
            dis[a][b]=dis[b][a]=d;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        //en
        sum=0;
        for(i=0;i<p-1;i++){
            enp[peat[i]][peat[i+1]]=enp[peat[i+1]][peat[i]]=sum+dis[peat[i]][peat[i+1]];
            sum=enp[peat[i]][peat[i+1]];
        }
        //st
        for(i=1;i<p-1;i++){
            stp[peat[i]][peat[i+1]]=stp[peat[i+1]][peat[i]]=enp[peat[i]][peat[i-1]];
        }
        tmp.u=s;
        tmp.w=t;
        ans[s]=0;
        dijk.push(tmp);
        while(!dijk.empty()){
            tmp=dijk.top();
            dijk.pop();
            u=tmp.u;
            noww=tmp.w;
            if(u==e) break;
            for(i=0;i<g[u].size();i++){
                next=g[u][i];
                tim=noww;
                if(mark[u][next]){
                    if(noww>=stp[u][next]&&noww<enp[u][next]){
                        tim=enp[u][next];
                    }
                }
                if(tim+dis[u][next]<ans[next]){
                    ans[next]=tim+dis[u][next];
                    tmp.w=ans[next];
                    tmp.u=next;
                    dijk.push(tmp);
                }
            }
        }
        printf("%lld",ans[e]-t);
        for(i=1;i<=n;i++) g[i].clear();
        while(!dijk.empty()) dijk.pop();
    }
    return 0;
}
/*
2
6 5
1 6 20 4
5 3 2 4
1 2 2
2 3 8
2 4 3
3 5 15
3 6 10

8 9
1 5 5 5
1 2 3 4 5
1 2 8
2 3 10
2 7 4
3 4 23
3 6 5
4 8 4
4 5 5
6 8 3
6 7 40
*/
