/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010];
priority_queue<int > heap;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,k,ans;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++)
        cin >> a[i];
    ans = 0;
    ans+=(a[1]-1)+(n-a[m]);
    for(int i=2;i<=m;i++)
        heap.push(a[i]-a[i-1]-1);
    k--;
    while(k && !heap.empty()){
        ans+=heap.top();
        heap.pop();
        k--;
    }
    cout << n-ans-m << "\n";
    return 0;
}