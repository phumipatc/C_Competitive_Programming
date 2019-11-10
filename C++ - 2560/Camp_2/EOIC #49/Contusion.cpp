/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[10100][10100],countt[100000100];
int main()
{
    int n,x,y,c,idx;
    scanf("%d %d %d %d",&n,&x,&y,&c);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mic[i][j]=abs(i-x)+abs(j-y);
            countt[mic[i][j]]++;
//            printf("%d ",mic[i][j]);
        }
//        printf("\n");
    }
    for(int i=1;i<=n*n;i++){
        countt[i]+=countt[i-1];
//        printf("%d ",countt[i]);
    }
    idx=lower_bound(countt,countt+(n*n),c)-countt;
    printf("%d\n",idx);
    return 0;
}
