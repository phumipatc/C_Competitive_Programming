/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define ZERO 2500000
using namespace std;
int qs[55][55],countt[5000010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&qs[i][j]);
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //First left - Second right
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int temp = qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1];
                    countt[temp+ZERO]++;
                }
            }
            for(int k=i+1;k<=n;k++){
                for(int l=j+1;l<=n;l++){
                    int temp = qs[k][l]-qs[k][j]-qs[i][l]+qs[i][j];
                    ans+=countt[temp+ZERO];
                }
            }
            for(int k=1;k<=i;k++){
                for(int l=1;l<=j;l++){
                    int temp = qs[i][j]-qs[k-1][j]-qs[i][l-1]+qs[k-1][l-1];
                    countt[temp+ZERO] = 0;
                }
            }
            //First right - Second left
            for(int k=i;k>=1;k--){
                for(int l=j;l<=n;l++){
                    int temp = qs[i][l]-qs[k-1][l]-qs[i][j-1]+qs[k-1][j-1];
                    countt[temp+ZERO]++;
                }
            }
            for(int k=i+1;k<=n;k++){
                for(int l=j-1;l>=1;l--){
                    int temp = qs[k][j-1]-qs[i][j-1]-qs[k][l-1]+qs[i][l-1];
                    ans+=countt[temp+ZERO];
                }
            }
            //reset
            for(int k=i;k>=1;k--){
                for(int l=j;l<=n;l++){
                    int temp = qs[i][l]-qs[k-1][l]-qs[i][j-1]+qs[k-1][j-1];
                    countt[temp+ZERO] = 0;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
