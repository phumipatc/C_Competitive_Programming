/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[255][255];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]+=max(a[i-1][j],a[i][j-1]);
        }
    }
    printf("%d\n",a[n][m]);
	return 0;
}
