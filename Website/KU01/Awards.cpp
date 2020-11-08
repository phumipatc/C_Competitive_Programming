/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    language: C++
    Algo	: Quicksum
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
int a[2][310],zr[2][310];
int mark[610];
vector<int > rmd;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[0][i];
        zr[0][i] = zr[0][i-1]+(a[0][i] == 0);
        mark[a[0][i]] = 1;
        a[0][i]+=a[0][i-1];
    }
    for(int i=1;i<=n;i++){
        cin >> a[1][i];
        zr[1][i] = zr[1][i-1]+(a[1][i] == 0);
        mark[a[1][i]] = 1;
        a[1][i]+=a[1][i-1];
    }
    rmd.push_back(0);
    for(int i=2*n;i>=1;i--){
        if(mark[i]) continue;
        rmd.push_back(i);
    }
    for(int i=1;i<rmd.size();i++)
        rmd[i]+=rmd[i-1];
    int maxx = 0,sum;
    for(int i=1;i<=n;i++){
        sum = a[0][i] + (a[1][n]-a[1][i-1]) + rmd[zr[0][i]+(zr[1][n]-zr[1][i-1])];
        maxx = max(maxx,sum);
    }
    cout << maxx << '\n';
    return 0;
}