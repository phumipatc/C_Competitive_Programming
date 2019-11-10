/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
queue<int > que;
int n,m,S,T;
int F[110][110],p[110],mark[110];
bool spath(){
    int i;
    memset(mark,-1,sizeof mark);
    mark[S] = 0;
    que.push(S);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(i=1;i<=n;i++){
            if(F[now][i] && mark[i] == -1){
                mark[i] = mark[now]+1;
                p[i] = now;
                que.push(i);
            }
        }
    }
    return mark[T]!=-1;
}
int push_flow(int now,int flow){
    if(now == S)    return flow;
    flow = push_flow(p[now],min(flow,F[p[now]][now]));
    F[p[now]][now]-=flow;
    F[now][p[now]]+=flow;
    return flow;
}
int main(){
    int i,j,k,l,a,b,c,d;
    scanf("%d %d %d %d",&n,&m,&S,&T);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&a,&b,&c);
        F[a][b] = c;
    }
    int maxx = 0;
    while(spath()){
        maxx+=push_flow(T,1e9);
    }
    printf("%d\n",maxx);
	return 0;
}
