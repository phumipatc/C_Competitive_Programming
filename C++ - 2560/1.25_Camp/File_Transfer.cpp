/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[1010];
int mark[1010];
void transfer(int now){
    int i;
    for(i=0;i<(int)g[now].size();i++){
        if(mark[g[now][i]]==-1){
            mark[g[now][i]]=1;
            transfer(g[now][i]);
        }
    }
}
int main(){
    int n,m,i,q,r,s;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
    }
    while(q--){
        scanf("%d %d",&r,&s);
        memset(mark,-1,sizeof(mark));
        mark[r]=1;
        transfer(r);
        if(mark[s]==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
return 0;
}
