/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long r,c,a[2100][2100];
void pass(long long i,long long j){
    a[i][j]=0;
    if(a[i+1][j-1] && i+1<=r && j-1>=1) pass(i+1,j-1);
    if(a[i+1][j] && i+1<=r)             pass(i+1,j);
    if(a[i+1][j+1] && i+1<=r && j+1<=c) pass(i+1,j+1);
    if(a[i-1][j-1] && i-1>=1 && j-1>=1) pass(i-1,j-1);
    if(a[i-1][j] && i-1>=1)             pass(i-1,j);
    if(a[i-1][j+1] && i-1>=1 && j+1<=c) pass(i-1,j+1);
    if(a[i][j-1] && j-1>=1)             pass(i,j-1);
    if(a[i][j+1] && j+1<=c)             pass(i,j+1);
}
int main()
{
    char t;
    long long i,j,ans=0;
    scanf("%lld %lld",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf(" %c",&t);
            a[i][j]=t-'0';
        }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(a[i][j]){
                pass(i,j);
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
4 5
10011
00001
01100
10011

4 4
0010
1010
0100
1111
*/
