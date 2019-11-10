/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tri[2][100100],qsum[2][100100];
int main()
{
    int n,d,i,j;
    scanf(" %d %d",&n,&d);
    tri[1][0]=1,qsum[1][0]=1;
    for(i=2;i<=n;i++){
        for(j=0;j<=d;j++){
            if(j!=0) qsum[(i+1)%2][j]=qsum[(i+1)%2][j-1]+tri[(i+1)%2][j];
            else qsum[(i+1)%2][j]=1;
            qsum[(i+1)%2][j]%=1000000007;
            if(j<i) tri[i%2][j]=qsum[(i+1)%2][j];
            else tri[i%2][j]=(qsum[(i+1)%2][j]+1000000007)-qsum[(i+1)%2][j-i];
            tri[i%2][j]%=1000000007;
        }
    }
    printf("%lld",tri[n%2][d]);
    return 0;
}
