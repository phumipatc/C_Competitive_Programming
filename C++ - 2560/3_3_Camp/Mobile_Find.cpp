/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[35][35],dir[2][4] = {{0,0,1,-1},{1,-1,0,0}};
int main(){
    int q,n,m,ai,aj,maxx;
    cin >> q;
    while(q--){
        maxx = -1;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin >> a[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=0;k<4;k++){
                    int ni = i+dir[0][k],nj = j+dir[1][k];
                    if(ni<=0 || nj<=0 || ni>n || nj>m)  continue;
                    if(abs(a[i][j]-a[ni][nj])>10)       continue;
                    if(a[i][j]+a[ni][nj]<=maxx)         continue;
                    ai = i,aj = j;
                    maxx = a[i][j]+a[ni][nj];
                }
            }
        }
        cout << ai << ' ' << aj << endl;
    }
    return 0;
}
