/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<(n+1)/2;i++){
        for(j=i;j<n/2;j++)
            printf("-");
        for(j=i;j>=0;j--)
            printf("*");
        for(j=i;j>0;j--)
            printf("*");
        for(j=i;j<n/2;j++)
            printf("-");
        printf("\n");
    }
    for(i=0;i<n/2;i++){
        for(j=i;j>=0;j--)
            printf("-");
        for(j=i;j<n/2;j++)
            printf("*");
        for(j=i;j<(n/2)-1;j++)
            printf("*");
        for(j=i;j>=0;j--)
            printf("-");
        printf("\n");
    }
return 0;
}
