/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[5100],b[5100];
int LCS[5100][5100];
int main(){
    int n,i,j;
    scanf("%d %s",&n,a+1);
    for(i=1;i<=n;i++)
        b[i]=a[n-i+1];
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i]==b[j])
                LCS[i][j]=LCS[i-1][j-1]+1;
            else
                LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
        }
    }
    printf("%d",n-LCS[n][n]);
    return 0;
}
