#include<stdio.h>
int a[15][15];
int main()
{
    int i,j,k,sum1,sum2,ans1 = 0,ans2 = 0;
    for(i=1; i<=9; i++)
    {
        for(j=1; j<=9; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            if(!a[i][j]){
                sum1 = sum2 = 0;
                for(k=1;k<=9;k++){
                    sum1+=a[i][k];
                    sum2+=a[k][j];
                }
                if(45-sum1<=45-sum2){
                    if(!ans1)   ans1 = 45-sum1;
                    else        ans2 = 45-sum1;
                }else{
                    if(!ans1)   ans1 = 45-sum2;
                    else        ans2 = 45-sum2;
                }
            }
        }
    }
    if(ans1>ans2)   printf("%d %d\n",ans2,ans1);
    else            printf("%d %d\n",ans1,ans2);
}
/*
9 8 5 4 2 6 3 1 7
4 1 0 3 9 7 5 2 8
7 2 3 1 5 8 4 6 9
1 6 2 7 3 4 9 8 5
8 9 7 6 1 5 2 4 3
5 3 4 2 8 0 6 7 1
3 7 1 5 6 2 8 9 4
2 4 9 8 7 3 1 5 6
6 5 8 9 4 1 7 3 2

9 8 5 4 2 6 3 1 7
4 1 6 3 9 7 5 2 8
7 2 3 1 5 8 4 6 9
1 6 2 7 3 4 9 8 5
8 9 7 6 1 5 2 4 3
5 3 4 2 8 9 6 7 1
3 7 1 5 6 2 8 9 4
2 4 9 8 7 3 1 5 6
6 5 8 9 4 1 7 3 2
*/
