/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[5][5];
int main()
{
    int n,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i]+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            for(int k=i+1;k<=n;k++){
                if(a[i][j]==a[k][j])    ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
