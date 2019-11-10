/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n+2;i++){
            for(int j=i+1;j<=n+2;j++)
                printf(".");
            for(int j=1;j<=i;j++)
                printf("#");
            for(int j=1;j<=n+2;j++){
                if(i == 1 || j == 1 || j == n+2 || i == n+2)
                    printf("+");
                else
                    printf("#");
            }
            printf("\n");
        }
        for(int i=1;i<=n+2;i++){
            for(int j=1;j<=n+2;j++){
                if(i == 1 || j == 1 || j == n+2 || i == n+2)
                    printf("#");
                else
                    printf("+");
            }
            for(int j=i;j<=n+2;j++)
                printf("+");
            for(int j=1;j<i;j++)
                printf(".");
            printf("\n");
        }
    }
    return 0;
}