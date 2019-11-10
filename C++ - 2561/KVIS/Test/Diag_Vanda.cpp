/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[410][410],toright[410][410],toleft[410][410];
int main(){
    int n,ans = -1e9;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            toright[i][j] = a[i][j]+toright[i-1][j-1];
        }
        for(int j=n;j>=1;j--)
            toleft[i][j] = a[i][j]+toleft[i-1][j+1];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=min(n-i,n-j);k++){
                ans = max(ans,(toright[i+k][j+k]-toright[i-1][j-1])-(toleft[i+k][j]-toleft[i-1][j+k+1]));
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
