/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],b[1010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    b[0]=(a[0][1]-a[1][2]+a[0][2])/2;
    printf("%d ",b[0]);
    for(i=1;i<n;i++){
        b[i]=a[0][i]-b[0];
        printf("%d ",b[i]);
    }
    return 0;
}
