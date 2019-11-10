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
    if(n%2==1){
        for(i=0;i<(n+1)/2;i++){
            for(j=i;j>0;j--)
                printf(" ");
            for(j=i;j<(n+1)/2;j++)
                printf("*");
            for(j=i;j<((n+1)/2)-1;j++){
                printf("*");
            }
            for(j=i;j>0;j--)
                printf(" ");
            printf("\n");
        }
        for(i=0;i<n/2;i++){
            for(j=i+1;j<n/2;j++)
                printf(" ");
            for(j=i+1;j>0;j--)
                printf("*");
            printf("*");
            for(j=i+1;j>0;j--)
                printf("*");
            printf("\n");
        }
    }else
        printf("error\n");
return 0;
}
