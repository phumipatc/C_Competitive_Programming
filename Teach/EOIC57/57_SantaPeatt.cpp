/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010];
int l[100010],r[100010],mark[100010],lim[100010];
vector<int > ans;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,u,v,st;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++){
        cin >> v;
        lim[a[i]] = v;
    }
    for(int i=1;i<n;i++)
        r[a[i]] = a[i+1];
    for(int i=2;i<=n;i++)
        l[a[i]] = a[i-1];
    st = a[1];
    while(m--){
        cin >> u >> v;
        mark[u] = 1;
        r[l[v]] = u;
        l[u] = l[v];
        r[u] = v;
        l[v] = u;
        if(st == v) st = u;
    }
    int now = st,sum = 0;
    while(now!=0){
        sum+=mark[now];
        if(lim[now]!=0 && lim[now]<=sum){
            now = r[now];
            continue;
        }
        ans.push_back(now);
        now = r[now];
    }
    cout << ans.size() << "\n";
    for(auto x:ans)
        cout << x << " ";
    return 0;
}