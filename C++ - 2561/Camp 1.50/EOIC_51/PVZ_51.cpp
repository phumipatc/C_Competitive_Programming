/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(n*2)+2;j++)
                printf(" ");
            for(int j=i;j<n;j++)
                printf(" ");
            for(int j=1;j<=i;j++)
                printf("*");
            for(int j=1;j<i;j++)
                printf("*");
            for(int j=i;j<n;j++)
                printf(" ");
            printf("\n");
        }
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n;j++)
                printf(" ");
            for(int j=i;j<=n;j++)
                printf("*");
            printf(" ");
            for(int j=1;j<i;j++)
                printf("+");
            for(int j=1;j<=(n*2)+1;j++){
                if(i == 1)  printf(" ");
                else        printf("+");
            }
            for(int j=1;j<i;j++)
                printf("+");
            printf(" ");
            for(int j=i;j<=n;j++)
                printf("*");
            printf("\n");
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<n;j++)
                printf(" ");
            for(int j=1;j<=i;j++)
                printf("*");
            printf(" ");
            for(int j=1;j<=(4*n)+1;j++)
                printf("+");
            printf(" ");
            for(int j=1;j<=i;j++)
                printf("*");
            printf("\n");
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++)
                printf(" ");
            for(int j=i;j<n;j++)
                printf("*");
            printf(" ");
            for(int j=1;j<=(4*n)+1;j++)
                printf("+");
            printf(" ");
            for(int j=i;j<n;j++)
                printf("*");
            printf("\n");
        }
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<=n;j++)
                printf(" ");
            for(int j=1;j<i;j++)
                printf("*");
            printf(" ");
            for(int j=i;j<=n;j++)
                printf("+");
            for(int j=1;j<=(2*n)+1;j++){
                if(i == n+1)    printf(" ");
                else            printf("+");
            }
            for(int j=i;j<=n;j++)
                printf("+");
            printf(" ");
            for(int j=1;j<i;j++)
                printf("*");
            printf("\n");
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(2*n)+2;j++)
                printf(" ");
            for(int j=1;j<i;j++)
                printf(" ");
            for(int j=i;j<=n;j++)
                printf("*");
            for(int j=i;j<n;j++)
                printf("*");
            printf("\n");
        }
    }
	return 0;
}
