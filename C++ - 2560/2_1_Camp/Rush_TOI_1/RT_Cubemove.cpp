/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],mic[110][110];
int main()
{
    int n,m,i,j,k,l,r,c;
    cin >> n >> m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=1;
    for(i=0;i<m;i++){
        cin >> r >> c;
        a[r][c]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            mic[i][j]=a[i][j]+mic[i-1][j]+mic[i][j-1]-mic[i-1][j-1];
    int minn=1e9,ans;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                for(l=1;l<=n;l++){
                    if((k-i+1)*(l-j+1)==m){
                        ans=mic[k][l]-mic[k][j-1]-mic[i-1][l]+mic[i-1][j-1];
                        minn=min(minn,ans);
                    }
                }
            }
        }
    }
    cout << minn << endl;
    return 0;
}
