/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100],b[1100][1100];
int main()
{
    int n,m,i,j,maxx=-1,num;
    scanf("%d %d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            b[i][j]=1;
    for(i=m-1;i>0;i--){
        for(j=1;j<=n;j++){
            if(i%2==1){
                if(a[i+1][j]==a[i+1][j-1]){
                    b[i][j]=b[i+1][j]+b[i+1][j-1];
                }else if(a[i+1][j]>a[i+1][j-1])   b[i][j]=b[i+1][j];
                else    b[i][j]=b[i+1][j-1];
                a[i][j]=max(a[i+1][j],a[i+1][j-1])+a[i][j];
            }else{
                if(a[i+1][j]==a[i+1][j+1]){
                    b[i][j]=b[i+1][j]+b[i+1][j+1];
                }else if(a[i+1][j]>a[i+1][j+1]) b[i][j]=b[i+1][j];
                else    b[i][j]=b[i+1][j+1];
                a[i][j]=max(a[i+1][j],a[i+1][j+1])+a[i][j];
            }
        }
    }
//    for(i=1;i<=m;i++){
//        for(j=1;j<=n;j++){
//            printf("%d\t",b[i][j]);
//        }
//        printf("\n");
//    }
    for(j=1;j<=n;j++){
        if(maxx==a[1][j])   num+=b[1][j];
        else if(maxx<a[1][j]){
            maxx=a[1][j];
            num=b[1][j];
        }
    }
    printf("%d %d\n",maxx,num);
    return 0;
}
/*
5 4
8 10 25 3
4 12 33 1
4 51 13 4
1 20 11 12
1 5 6 25

4 3
0 10 10
0 14 0
0 17 17
0 20 0

7 5
10 8 25 13 16
4 23 12 1 14
14 17 0 11 26
6 3 3 8 10
4 5 16 5 14
8 4 4 1 7
8 3 1 4 5
*/
