/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs1[100100][15][15],qs2[100100][15][15];
int main(){
    int r,c,n,m,a,b,e,d;
    scanf("%d %d %d %d",&r,&c,&n,&m);
    while(n--){
        scanf("%d %d %d %d",&a,&b,&d,&e);
        for(int i=1;i<=c;i++){
            for(int j=i;j<=c;j++){
                if(i<b && j<b)  continue;
                if(i>e && j>e)  continue;
                qs1[a][i][j]++;
                qs2[d+1][i][j]++;
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int k=j;k<=c;k++){
                qs1[i][j][k]+=qs1[i-1][j][k];
                qs2[i][j][k]+=qs2[i-1][j][k];
            }
        }
    }
    while(m--){
        scanf("%d %d %d %d",&a,&b,&d,&e);
        printf("%d\n",qs1[d][b][e]-qs2[a][b][e]);
    }
    return 0;
}
