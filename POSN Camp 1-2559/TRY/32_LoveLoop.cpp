/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=i;j<i+4;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            printf("%d ",j);
        }
        for(j=1;j<i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
return 0;
}
