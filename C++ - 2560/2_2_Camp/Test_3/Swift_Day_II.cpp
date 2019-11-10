/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector < int > g[25];
int mark[25],minn=1e9,n,m,mem[15];
void play(int now){
    int countt=0;
    if(now==n+1){
        memset(mem,0,sizeof mem);
        for(int i=1;i<=n;i++){
            if(mark[i]==1){
                countt++;
                for(int j=0;j<g[i].size();j++)
                    mem[g[i][j]]=1;
            }
        }
        for(int i=1;i<=m;i++)
            if(mem[i]==0)
                return ;
        minn=min(minn,countt);
        return ;
    }
    mark[now]=1;
    play(now+1);
    mark[now]=0;
    play(now+1);
}
int main(){
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int num;
            scanf("%d",&num);
            g[i].push_back(num);
        }
    }
    play(1);
    printf("%d\n",minn);
    return 0;
}
/*
1
6
1 2 3
3 4 8
3 5 4
5 6 7
2 3 4
*/
