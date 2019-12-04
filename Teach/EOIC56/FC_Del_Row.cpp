/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[1010][1010];
string col[1010];
map<string ,int > mapp;
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,ch;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i]+1;
    for(int i=n;i>=1;i--){
        mapp.clear();
        ch = 1;
        for(int j=1;j<=m;j++){
            col[j].push_back(a[i][j]);
            if(mapp[col[j]])    ch = 0;
            if(!ch)             continue;
            mapp[col[j]]++;
        }
        if(ch){
            cout << i-1 << "\n";
            break;
        }
    }
    return 0;
}
/*
4 6
mrtaxi
mrtaxi
mitaxi
mitezi
*/