/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10][10],mark[10][10],ans = 0,dir[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1} };
void change(int i,int j){
    for(int k=0;k<8;k++){
        int ni = i+dir[0][k],nj = j+dir[1][k];
        if(ni<=0 || nj<=0 || ni>9 || nj>9)  continue;
        a[ni][nj]^=1;
    }
}
void permute(int state){
    if(state == 3){
        int sum = 0;
        for(int i=1;i<=9;i++)
            for(int j=1;j<=9;j++)
                sum+=a[i][j];
        ans = max(ans,sum);
        return ;
    }
    for(int i=2;i<9;i++){
        for(int j=2;j<9;j++){
            if(mark[i][j])  continue;
            mark[i][j] = 1;
            change(i,j);
            permute(state+1);
            change(i,j);
            mark[i][j] = 0;
        }
    }
}
int main(){
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            cin >> a[i][j];
    permute(0);
    cout << ans << endl;
    return 0;
}
