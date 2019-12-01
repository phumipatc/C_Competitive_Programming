/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > warp[500010];
int mark[500010];
priority_queue<int > heap;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,k,u,v;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        warp[u].push_back(v);
    }
    for(int i=1;i<=k;i++){
        cin >> u;
        mark[u] = 1;
    }
    for(int i=1;i<n;i++){
        if(mark[i]) continue;
        warp[i].push_back(i+1);
    }
    memset(mark,0,sizeof mark);
    heap.push(1);
    int maxx = 0;
    while(!heap.empty()){
        int now = heap.top();
        heap.pop();
        maxx = max(maxx,now);
        for(auto x:warp[now]){
            if(mark[x]) continue;
            mark[x] = 1;
            heap.push(x);
        }
    }
    if(maxx == n)   cout << "1\n";
    else            cout << "0 " << maxx << '\n';
    return 0;
}