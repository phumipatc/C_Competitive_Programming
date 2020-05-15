/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int p[30],mark[30],have[30];
char a[1000010];
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    for(int i=0;i<26;i++)   p[i] = i;
    int n,ru,rv;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a+1;
        int len = strlen(a+1);
        ru = find_root(a[1]-'a');
        have[a[1]-'a'] = 1;
        for(int i=2;i<=len;i++){
            rv = find_root(a[i]-'a');
            have[a[i]-'a'] = 1;
            p[rv] = ru;
        }
    }
    int ans = 0;
    for(int i=0;i<26;i++){
        if(!have[i])    continue;
        ru = find_root(i);
        if(mark[ru])    continue;
        ans++;
        mark[ru] = 1;
    }
    cout << ans << '\n';
    return 0;
}