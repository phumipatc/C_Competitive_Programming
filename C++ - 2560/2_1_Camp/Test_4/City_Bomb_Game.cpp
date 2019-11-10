/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,player;
};
vector< int> g[1100];
queue< int> q;
int mark[1100],from[1100];
int main(){
    int n,k,u,v,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    q.push({k,1});
    while(!q.empty()){
        A temp=q.front();
        q.pop();
        mark[temp.pos]=temp.player^1;
        if(g[temp.pos].size()==0 && mark[temp.pos]==0){
            printf("First player wins %d\n");
        }
    }
    return 0;
}
