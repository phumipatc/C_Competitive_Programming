/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010];
set<int > sett;
vector<int > v;
int mark[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,minn = 0,maxx = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sett.insert(a[i]);
    }
    for(auto x:sett)
        v.push_back(x);
    for(int i=0;i<v.size();i++){
        minn++;
        if(i!=0 && v[i]-v[i-1] == 1)                v[i]--,minn--;
        else if(i!=v.size()-1 && v[i+1]-v[i]<=2)    v[i+1] = (v[i+1]+v[i]+1)/2,i++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!mark[a[i]-1]){
            mark[a[i]-1] = 1;
            maxx++;
        }else if(!mark[a[i]]){
            mark[a[i]] = 1;
            maxx++;
        }else if(!mark[a[i]+1]){
            mark[a[i]+1] = 1;
            maxx++;
        }
    }
    cout << minn << ' ' << maxx << '\n';
    return 0;
}