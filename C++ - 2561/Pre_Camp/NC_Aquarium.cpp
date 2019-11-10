/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,zone;
};
queue< A> que;
struct B{
    int x,y,co;
    bool operator <(const B & o)const{
        if(co != o.co)  return co > o.co;
    }
};
priority_queue< B> heap;
char a[110][110];
int cost[110][110],mark[110][110][2],p[100100];
int findroot(int n){
    if(n == p[n])   return n;
    else            return p[n] = findroot(p[n]);
}
int main(){
    int n,m,si = 0,nowi,nowj,nowz,i,j,nexti,nextj,ra,rb,ans = 0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&cost[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(mark[i][j][1] == 0){
                si++;
                mark[i][j][1] = si;
                que.push({i,j,1});
                while(!que.empty()){
                    nowi = que.front().i;
                    nowj = que.front().j;
                    nowz = que.front().zone;
                    que.pop();
                    mark[nowi][nowj][nowz] = si;
                    if(nowz == 1){
                        if(a[nowi][nowj] == '/'){
                            nexti = nowi-1,nextj = nowj;
                            if(nexti>=1 && mark[nexti][nextj][2] == 0)
                                que.push({nexti,nextj,2});
                            nexti = nowi,nextj = nowj-1;
                            if(nextj>=1){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                            }
                        }
                        if(a[nowi][nowj] == '\\'){
                            nexti = nowi-1,nextj = nowj;
                            if(nexti>=1 && mark[nexti][nextj][2] == 0)
                                que.push({nexti,nextj,2});
                            nexti = nowi,nextj = nowj+1;
                            if(nextj<=m){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                            }
                        }
                    }
                    if(nowz == 2){
                        if(a[nowi][nowj] == '/'){
                            nexti = nowi+1,nextj = nowj;
                            if(nexti <= n && mark[nexti][nextj][1]==0)
                                que.push({nexti,nextj,1});
                            nexti = nowi,nextj = nowj+1;
                            if(nextj<=m){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                            }
                        }
                        if(a[nowi][nowj] == '\\'){
                            nexti = nowi+1,nextj = nowj;
                            if(nexti<=n && mark[nexti][nextj][1]==0)
                                que.push({nexti,nextj,1});
                            nexti = nowi,nextj = nowj-1;
                            if(nextj>=1){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                            }
                        }
                    }
                }
            }
            if(mark[i][j][2] == 0){
                si++;
                mark[i][j][2] = si;
                que.push({i,j,2});
                while(!que.empty()){
                    nowi = que.front().i;
                    nowj = que.front().j;
                    nowz = que.front().zone;
                    que.pop();
                    mark[nowi][nowj][nowz] = si;
                    if(nowz == 1){
                        if(a[nowi][nowj] == '/'){
                            nexti = nowi-1,nextj = nowj;
                            if(nexti>=1 && mark[nexti][nextj][2] == 0)
                                que.push({nexti,nextj,2});
                            nexti = nowi,nextj = nowj-1;
                            if(nextj>=1){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                            }
                        }
                        if(a[nowi][nowj] == '\\'){
                            nexti = nowi-1,nextj = nowj;
                            if(nexti>=1 && mark[nexti][nextj][2] == 0)
                                que.push({nexti,nextj,2});
                            nexti = nowi,nextj = nowj+1;
                            if(nextj<=m){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                            }
                        }
                    }
                    if(nowz == 2){
                        if(a[nowi][nowj] == '/'){
                            nexti = nowi+1,nextj = nowj;
                            if(nexti<=n && mark[nexti][nextj][1] == 0)
                                que.push({nexti,nextj,1});
                            nexti = nowi,nextj = nowj+1;
                            if(nextj<=m){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                            }
                        }
                        if(a[nowi][nowj] == '\\'){
                            nexti = nowi+1,nextj = nowj;
                            if(nexti<=n && mark[nexti][nextj][1] == 0)
                                que.push({nexti,nextj,1});
                            nexti = nowi,nextj = nowj-1;
                            if(nextj>=1){
                                if(a[nexti][nextj] == '/' && mark[nexti][nextj][2] == 0)
                                    que.push({nexti,nextj,2});
                                if(a[nexti][nextj] == '\\' && mark[nexti][nextj][1] == 0)
                                    que.push({nexti,nextj,1});
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mark[i][j][1]!=mark[i][j][2])
                heap.push({mark[i][j][1],mark[i][j][2],cost[i][j]});
    for(i=1;i<si;i++)   p[i]=i;
    while(!heap.empty()){
        nowi = heap.top().x;
        nowj = heap.top().y;
        nowz = heap.top().co;
        heap.pop();
        ra = findroot(nowi);
        rb = findroot(nowj);
        if(ra!=rb){
            p[ra] = rb;
            ans+=nowz;
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
2 2
\/
\\
7 10
12 9

1 3
/\\
4 3 5
*/
