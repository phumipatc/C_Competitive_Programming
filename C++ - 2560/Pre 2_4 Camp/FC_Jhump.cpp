/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
vector<int> g[200100];
int main(){
    int q,idx=1,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&u,&v);
            if(!mapp[u])    mapp[u]=idx++;
            if(!mapp[v])    mapp[v]=idx++;
            g[mapp[u]].push_back(mapp[v]);
        }
    }
    return 0;
}
