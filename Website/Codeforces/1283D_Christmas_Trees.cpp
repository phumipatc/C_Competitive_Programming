/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010];
pair<LL ,LL > now;
queue<pair<LL ,int> > que;
map<LL ,LL > mapp;
vector<LL > ans;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL n,m;
    cin >> n >> m;
    for(LL i=1;i<=n;i++)
        cin >> a[i],mapp[a[i]] = 1;
    sort(a+1,a+n+1);
    for(LL i=1;i<=n;i++){
        if(!mapp[a[i]-1])   que.push({a[i]-1,1}),mapp[a[i]-1] = 1;
        if(!mapp[a[i]+1])   que.push({a[i]+1,1}),mapp[a[i]+1] = 1;
    }
    LL sum = 0;
    while(m--){
        now = que.front();
        que.pop();
        sum+=now.second;
        ans.push_back(now.first);
        if(!mapp[now.first-1])  que.push({now.first-1,now.second+1}),mapp[now.first-1] = 1;
        if(!mapp[now.first+1])  que.push({now.first+1,now.second+1}),mapp[now.first+1] = 1;
    }
    cout << sum << '\n';
    for(auto x:ans)
        cout << x << ' ';
    return 0;
}