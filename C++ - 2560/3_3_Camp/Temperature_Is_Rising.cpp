/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int m,a[25][25],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}},ans = -10;
void recurse(int i,int j){
    for(int k=0;k<4;k++){
        int ni = i+dir[0][k],nj = j+dir[1][k];
        if(ni<1 || nj<1 || ni>m || nj>m)    continue;
        if(a[ni][nj]<=a[i][j])              continue;
        if(a[ni][nj] == 100)                continue;
        recurse(ni,nj);
    }
    ans = max(ans,a[i][j]);
}
int main(){
    int sti,stj;
    cin >> m >> stj >> sti;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    recurse(sti,stj);
    cout << ans << endl;
    return 0;
}
