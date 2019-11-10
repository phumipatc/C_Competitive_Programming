/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[50005];
int in[50005],ans[50005],change[50005];
priority_queue< int,vector<int>,greater<int>> heap;
int main(){
    int n,m,u,v,st,idx;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[v].push_back(u);
        in[u]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])
            heap.push(i);
    idx = 0;
    while(!heap.empty()){
        int now = heap.top();
        if(heap.size()>=2)  change[idx] = 1;
        heap.pop();
        ans[idx++] = now;
        for(int i=0;i<g[now].size();i++){
            in[g[now][i]]--;
            if(!in[g[now][i]])
                heap.push(g[now][i]);
        }
    }
    int ch = 0;
    for(int i=idx -1;i>=0;i--)
        if(change[i] && !ch)
            swap(ans[i],ans[i+1]),ch = 1;
    if(idx!=n){
        printf("Never\n");
        return 0;
    }else if(!ch)
        printf("Same\n");
    else
        printf("Different\n");
    for(int i=0;i<idx;i++)
        printf("%d ",ans[i]);
    return 0;
}
