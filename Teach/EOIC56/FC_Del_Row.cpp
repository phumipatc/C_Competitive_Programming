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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    for(int i=n;i>=1;i--){
        ch = 1;
        for(int j=1;j<=m;j++){
            col[j].push_back(a[i][j]);
            if(mapp[col[j]]){
                // cout << col[j] << '\n';
                ch = 0;
                break;
            }
            mapp[col[j]]++;
        }
        mapp.clear();
        if(ch){
            printf("%d\n",i-1);
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