/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],mark[200010];
vector<int > v,zero;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        mark[a[i]] = 1;
    }
    for(int i=n;i>=1;i--){
        if(mark[i]) continue;
        v.push_back(i);
    }
    for(int i=1;i<=n;i++){
        if(a[i])    continue;
        zero.push_back(i);
    }
    for(int i=0;i<v.size()-1;i++)
        if(v[i] == zero[i])
            swap(v[i],v[i+1]);
    for(int i=v.size()-1;i>=1;i--)
        if(v[i] == zero[i])
            swap(v[i],v[i-1]);
    for(int i=1,c=0;i<=n;i++){
        if(a[i])    continue;
        a[i] = v[c++];
    }
    for(int i=1;i<=n;i++)
        cout << a[i] << ' ';
    return 0;
}