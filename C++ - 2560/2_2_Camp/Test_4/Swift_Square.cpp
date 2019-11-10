/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[15][10100],a[15];
int main(){
    int n,b;
    scanf("%d %d",&n,&b);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<=n;i++)
        for(j=1;j<=b;j++)
            mic[i][j]=1e9;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j<=b;j++){
            for(int k=1;k<=1000;k++){
                if(j+k*k>b)   continue;
                mic[i][j+k*k] = min(mic[i][j+k*k],mic[i-1][j]+(k-a[i])*(k-a[i]));
            }
        }
    }
    if(mic[n][b]==1e9)  printf("-1\n");
    else                printf("%d\n",mic[n][b]);
    return 0;
}
/*
3 9
1
3
3
*/
