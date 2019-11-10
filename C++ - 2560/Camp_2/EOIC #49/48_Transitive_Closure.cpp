/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]){
                for(k=1;k<=n;k++){
                    if(a[j][k])
                        a[i][k]=a[j][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i][j]){
                for(k=1;k<=n;k++){
                    if(a[j][k])
                        a[i][k]=a[j][k];
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
/*
4
0 0 1 0
1 0 0 1
0 0 0 0
0 1 0 0
*/
