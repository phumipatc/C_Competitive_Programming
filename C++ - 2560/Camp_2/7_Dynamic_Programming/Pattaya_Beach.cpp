/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[3200][3200],a[3200],b[3200];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==b[j]){
                mic[i][j]=mic[i-1][j-1]+1;
            }else{
                mic[i][j]=max(mic[i-1][j],mic[i][j-1]);
            }
        }
    }
    printf("%d\n",mic[n][n]);
    return 0;
}
