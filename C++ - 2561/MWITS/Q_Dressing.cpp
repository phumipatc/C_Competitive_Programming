/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[50010];
int in[50010],ans[50010],change[50010];
priority_queue<int > heap;
int main(){
    int n,m,u,v,st,idx;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[v].push_back(u);
        in[u]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        heap.push(-i);
    }
    idx = 0;
    while(!heap.empty()){
        if(heap.size()>=2)  change[idx] = 1;
        int now = -heap.top();
        heap.pop();
        ans[idx++] = now;
        for(auto x:g[now]){
            in[x]--;
            if(!in[x])  heap.push(-x);
        }
    }
    int ch = 0;
    for(int i=idx-1;i>=0;i--){
        if(change[i]){
            swap(ans[i],ans[i+1]);
            ch = 1;
            break;
        }
    }
    if(idx!=n){
        printf("Never\n");
        return 0;
    }else if(!ch)   printf("Same\n");
    else            printf("Different\n");
    for(int i=0;i<idx;i++)
        printf("%d ",ans[i]);
    return 0;
}
