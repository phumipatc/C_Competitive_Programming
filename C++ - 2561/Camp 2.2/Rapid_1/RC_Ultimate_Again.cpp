/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1010][1010];
int a[1010][1010],leftright[1010][1010];
int dp[1010][1010][4];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf(" %s",str[i]+1);
        for(int j=1;j<=m;j++)
            a[i][j] = (str[i][j] == '.');
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 0)    continue;
            leftright[i][j] = a[i][j]+leftright[i][j-1];
            dp[i][j][0] = min(leftright[i][j],dp[i-1][j][0]+1);
        }
        for(int j=m;j>=1;j--){
            if(a[i][j] == 0)    continue;
            leftright[i][j] = a[i][j]+leftright[i][j+1];
            dp[i][j][1] = min(leftright[i][j],dp[i-1][j][1]+1);
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 0)    continue;
            leftright[i][j] = a[i][j]+leftright[i][j-1];
            dp[i][j][2] = min(leftright[i][j],dp[i+1][j][2]+1);
        }
        for(int j=m;j>=1;j--){
            if(a[i][j] == 0)    continue;
            leftright[i][j] = a[i][j]+leftright[i][j+1];
            dp[i][j][3] = min(leftright[i][j],dp[i+1][j][3]+1);
        }
    }
    int maxx = 0,ci,cj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(maxx<min(dp[i][j][0],min(dp[i][j][1],min(dp[i][j][2],dp[i][j][3])))){
                maxx = min(dp[i][j][0],min(dp[i][j][1],min(dp[i][j][2],dp[i][j][3])));
                ci = i,cj = j;
            }
        }
    }
    // printf("%d %d %d\n",maxx,ci,cj);
    int st = cj-maxx+1,en = cj+maxx-1,temp = ci;
    while(st<=en){
        for(int j=st;j<=en;j++)
            str[temp][j] = 'x';
        temp--,st++,en--;
    }
    st = cj-maxx+1,en = cj+maxx-1,temp = ci;
    while(st<=en){
        for(int j=st;j<=en;j++)
            str[temp][j] = 'x';
        temp++,st++,en--;
    }
    for(int i=1;i<=n;i++){
        printf("%s\n",str[i]+1);
    }
	return 0;
}
/*
10 10
..#....#..
..........
.#....#...
.....#....
..........
.........#
....#.....
..#..#....
..........
.......#..
*/