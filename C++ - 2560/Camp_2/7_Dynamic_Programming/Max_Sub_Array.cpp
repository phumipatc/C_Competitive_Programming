/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <bits/stdc++.h>
using namespace std;
int a[510][510];
int main(){
    int n,i,j,k,ma=-100000000,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j];
        }
    }
	ma = a[1][1];
    for(k=1;k<=n;k++){
        for(i=1;i<=n-k+1;i++){
            for(j=1,sum=0;j<=n;j++){
                sum+=a[i+k-1][j]-a[i-1][j];
                if(sum<0)
                    sum=a[i+k-1][j]-a[i-1][j];
                if(sum>ma)
                    ma=sum;
            }
        }
    }
    printf("%d\n",ma);
    return 0;
}
/*
4 0 -2 7 0 9 2 -6 2 -4 1 -4 1 -4 8 0 -2
*/
