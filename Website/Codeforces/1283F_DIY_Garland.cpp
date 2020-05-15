/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
priority_queue<int > heap;
vector<pair<int ,int > > ans;
int a[200010],countt[200010],val[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a[i];
        countt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(countt[i])   continue;
        heap.push(-i);
    }
    for(int i=n-1;i>=1;i--){
        ans.push_back({a[i],-heap.top()});
        heap.pop();
        countt[a[i]]--;
        if(!countt[a[i]])   heap.push(-a[i]);
    }
    cout << a[1] << '\n';
    for(auto x:ans)
        cout << x.first << ' ' << x.second << '\n';
    return 0;
}