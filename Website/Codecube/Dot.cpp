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
    int n,countt=0,x,y,i,j;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        a[y][x]=1;
    }
    for(i=0;i<=1000;i++){
        for(j=0;j<=1000;j++){
            if(a[i][j]==1)
                countt++;
        }
    }
    printf("%d\n",countt);
return 0;
}
