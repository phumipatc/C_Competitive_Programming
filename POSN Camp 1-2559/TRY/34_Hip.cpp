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
        for(j=i;j<n;j++){
            printf(".");
        }
        printf("*");
        if(i==2)
            for(j=i;j<n;j++){
                printf("-");
            }
        for(j=i;j<n;j++){
            printf(".");
        }
        for(j=i+1;j<n;j++){
            printf(".");
        }
        printf("\n");
    }
return 0;
}
