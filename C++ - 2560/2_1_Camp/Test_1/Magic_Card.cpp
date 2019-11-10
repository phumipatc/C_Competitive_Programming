/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[5100][5100],a[5100],b[5100];
int main()
{
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)   cin >> a[i];
    for(int i=1;i<=m;i++)   cin >> b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mic[i][j]=max(mic[i][j],mic[i-1][j]);
            mic[i][j]=max(mic[i][j],mic[i][j-1]);
            mic[i][j]=max(mic[i][j],mic[i-1][j-1]+abs(a[i]-b[j]));
        }
    }
    cout << mic[n][m];
    return 0;
}
