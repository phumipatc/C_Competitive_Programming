/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[100010];
vector<int > factor;
int countt[100010][30];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,ch;
    cin >> q;
    while(q--){
        cin >> a+1;
        n = strlen(a+1);
        for(int i=1;i<=n;i++){
            countt[i][a[i]-'a']++;
            for(int j=0;j<26;j++)
                countt[i][j]+=countt[i-1][j];
        }
        factor.clear();
        for(int i=1;i<n;i++){
            if(n%i) continue;
            factor.push_back(i);
        }
        for(auto x:factor){
            ch = 1;
            for(int i=x+x;i<=n;i+=x){
                for(int j=0;j<26;j++){
                    if(countt[i][j]-countt[i-x][j] == countt[x][j]) continue;
                    ch = 0;
                    break;
                }
                if(!ch) break;
            }
            if(ch){
                for(int i=1;i<=x;i++)
                    cout << a[i];
                cout << '\n';
                break;
            }
        }
        if(!ch) cout << "-1\n";
        memset(countt,0,sizeof countt);
    }
    return 0;
}