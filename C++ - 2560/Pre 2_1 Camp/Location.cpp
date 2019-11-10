/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100];
int main()
{
    int r,c,i,j,maxx=-1,k,sum;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j];
        }
    }
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            a[i][j]+=a[i][j-1];
    for(i=k;i<=r;i++){
        for(j=k;j<=c;j++){
            maxx=max(maxx,a[i][j]+a[i-k][j-k]-a[i-k][j]-a[i][j-k]);
        }
    }
    printf("%d\n",maxx);
    return 0;
}
/*
6 4
3
7 8 5 1
0 3 5 2
3 3 2 9
9 7 8 9
4 3 5 9
8 6 5 2

5 10
2
5 9 2 9 1 2 8 9 1 6
9 1 3 9 8 4 2 1 5 7
2 7 9 3 8 5 2 7 6 8
1 6 2 1 7 7 1 9 4 1
8 5 2 3 9 8 5 6 3 3
*/
