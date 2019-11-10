/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long k,w,v,cnt;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
long long dist[12000],mark[12000];
vector <A>g[12000];
priority_queue<A>dijk;
A temp;
int main(){
    long long v,e,x,y,i,j,n,u,noww,cnttime=0;
    scanf("%lld %lld",&n,&e);
    for(i=0;i<=n;i++)
        dist[i]=1<<30;
    scanf("%lld %lld",&x,&y);
    temp.v=x,temp.k=1<<30,temp.w=0,dist[x]=0,temp.cnt=0;//add tempcnt
    mark[x]=1;
    dijk.push(temp);
    scanf("%lld %lld %lld %lld",&x,&temp.v,&temp.w,&temp.k);
    g[x].push_back(temp);
    while(e--){
        scanf("%lld %lld %lld",&x,&temp.v,&temp.w);
        temp.k=1<<30;
        g[x].push_back(temp);
    }
    while(!dijk.empty()){
        temp=dijk.top();
        dijk.pop();
        u=temp.v,noww=temp.w;
        for(i=0;i<g[u].size();i++){
            if(g[u][i].k>=noww&&noww+g[u][i].w<dist[g[u][i].v]){//deletecnttime
                dist[g[u][i].v]=noww+g[u][i].w;
                temp.v=g[u][i].v,temp.w=noww+g[u][i].w;
                dijk.push(temp);
                //cnttime+=temp.w;
            }
            //mark[g[u][i].v]=1;
        }
    }
    printf("%lld",dist[y]);
return 0;
}
/*
4 4
0 3
1 3 -10 10
0 1 5
0 3 10
1 3 3
2 3 5
*/
