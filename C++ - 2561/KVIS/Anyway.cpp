/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD (int)1e6
using namespace std;
int a[1010][1010],mark[1010][1010];
int main(){
    int r,c,k,i,j;
    cin >> r >> c >> k;
    r++,c++;
    while(k--){
        cin >> i >> j;
        i++,j++;
        mark[i][j] = 1;
    }
    a[0][1] = 1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mark[i][j])  a[i][j] = 0;
            else            a[i][j] = (a[i-1][j]+a[i][j-1])%MOD;
        }
    }
    printf("%d\n",a[r][c]);
	return 0;
}
