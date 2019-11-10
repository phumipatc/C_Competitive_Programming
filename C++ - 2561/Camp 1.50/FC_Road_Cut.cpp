/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010][1010];
int main(){
    int r,c,all = 0,temp,ans = -1e9;
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            all+=a[i][j];
        }
    }
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            cin >> b[i][j];
    for(int i=1;i<=r;i++){
        temp = all;
        for(int j=1;j<=c;j++){
            temp-=a[i][j];
            temp+=b[i-1][j]+b[i+1][j];
        }
        ans = max(ans,temp);
    }
    for(int j=1;j<=c;j++){
        temp = all;
        for(int i=1;i<=r;i++){
            temp-=a[i][j];
            temp+=b[i][j-1]+b[i][j+1];
        }
        ans = max(ans,temp);
    }
    cout << ans;
	return 0;
}
