/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1100][1100],table[100000][100000];
int main()
{
    int n,q,x,y,i,a,b;
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        mark[a][b]=1;
    }
    while(q--){
        scanf("%d %d",&x,&y);
        for(i=1;i<=x;i++){
            for(j=1;j<=y;j++){
                if(i==1 || j==1)    table[i][j]=1;
                else                table[i][j]=0;
            }
        }
        for(i=2;i<=x;i++){
            for(j=2;j<=y;j++){
                if(!mark[i][j]){
                    table[i][j]=table[i-1][j]+table[i][j-1];
                }
            }
        }
        printf("%d",table[x][y]);
    }
    return 0;
}
