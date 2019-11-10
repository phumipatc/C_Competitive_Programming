/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1001][1001][4],a[1001][1001];
int main(){
    int q,r,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                int maxx=-1;
                for(int k=0;k<3;k++)
                    maxx=max(maxx,max(mic[i-1][j][k],mic[i][j-1][k]));
                mic[i][j][0]=maxx;
                mic[i][j][1]=a[i][j]+max(mic[i-1][j][0],mic[i][j-1][0]);
                mic[i][j][2]=a[i][j]+max(mic[i-1][j][1],mic[i][j-1][1]);
            }
        }
        int maxx=-1;
        for(int i=0;i<3;i++)
            maxx=max(maxx,mic[r][c][i]);
        printf("%d\n",maxx);
        memset(mic,0,sizeof mic);
    }
    return 0;
}
