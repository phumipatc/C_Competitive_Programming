/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > v;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,r,g,b,maxx;
    cin >> q;
    while(q--){
        cin >> r >> g >> b;
        v.push_back(r);
        v.push_back(g);
        v.push_back(b);
        sort(v.begin(),v.end());
        if(v[0]+v[1]>=v[2]-1)   printf("YES\n");
        else                    printf("NO\n");
        v.clear();
    }
    return 0;
}