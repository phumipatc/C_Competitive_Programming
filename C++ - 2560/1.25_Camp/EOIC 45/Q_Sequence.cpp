/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200][1200];
int main(){
    int n,i,j,an,ans;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    an=(a[0][1]+a[0][2]-a[1][2])/2;
    printf("%d ",an);
    for(i=1;i<n;i++){
        ans=a[i][0]-an;
        printf("%d ",ans);
    }
return 0;
}
