/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
int k;
struct A{
    LL a[1<<6][1<<6];
    A operator * (const A&o) const{
        A temp;
        for(int i=0;i<1<<(k-1);i++){
            for(int j=0;j<1<<(k-1);j++){
                temp.a[i][j] = -INF;
                for(int l=0;l<1<<(k-1);l++)
                    temp.a[i][j] = max(temp.a[i][j],a[i][l]+o.a[l][j]);
            }
        }
        return temp;
    }
};
A p[30],ans;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,a,b;
    cin >> n >> k;
    if(k == 1){
        cin >> a >> b;
        cout << (LL )n*max(a,b) << "\n";
        return 0;
    }
    for(int i=0;i<1<<(k-1);i++)
        for(int j=0;j<1<<(k-1);j++)
            p[0].a[i][j] = -INF;
    for(int i=0;i<1<<k;i++)
        cin >> p[0].a[i>>1][i&((1<<(k-1))-1)];
    for(int i=1;i<30;i++)
        p[i] = p[i-1]*p[i-1];
    n-=k-1;
    for(int i=0;i<30;i++){
        if(n&(1<<i)){
            ans = ans*p[i];
        }
    }
    LL ret = 0;
    for(int i=0;i<1<<(k-1);i++)
        for(int j=0;j<1<<(k-1);j++)
            ret = max(ret,ans.a[i][j]);
    cout << ret << "\n";
    return 0;
}