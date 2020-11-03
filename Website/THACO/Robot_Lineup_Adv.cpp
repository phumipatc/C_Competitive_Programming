/*
    Author	: Phumipat C.
    School	: RYW
    Langauge: C++
    Algo    : DP & Fenwick Tree
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],b[200010];
int tree[400010];
LL dp[200010][2];  //0 = from left, 1 = from right
vector<int > comp;
void upd(int idx,int v){
    while(idx<=400003){
        tree[idx]+=v;
        idx+=idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx & -idx;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    comp.push_back(0);
    for(int i=1;i<=n;i++)
        cin >> a[i],comp.push_back(a[i]);
    for(int i=1;i<=m;i++)
        cin >> b[i],comp.push_back(b[i]);
    sort(comp.begin(),comp.end());
    for(int i=1;i<=n;i++)
        a[i] = lower_bound(comp.begin(),comp.end(),a[i])-comp.begin();
    for(int i=1;i<=m;i++)
        b[i] = lower_bound(comp.begin(),comp.end(),b[i])-comp.begin();
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++)
        upd(a[i],1);
    for(int i=1;i<=m;i++)
        dp[i][0] = dp[i-1][0]+query(n+m)-query(b[i])+i-1;
    for(int i=m;i>=1;i--)
        dp[i][1] = dp[i+1][1]+query(b[i])+i-1;
    LL maxx = 0;
    for(int i=0;i<=m;i++)
        maxx = max(maxx,dp[i][0]+dp[i+1][1]);
    cout << maxx << '\n';
}