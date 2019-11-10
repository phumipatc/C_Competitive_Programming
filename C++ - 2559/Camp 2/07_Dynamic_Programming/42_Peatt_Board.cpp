/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main(){
    int i,j,x1,x2,y1,y2,r,c,n;
    scanf("%d %d %d",&c,&r,&n);
    while(n--){
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        a[x1][y1]++,a[x1][y2+1]--;
        a[x2+1][y1]--,a[x2+1][y2+1]++;
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            a[i][j]+=(a[i][j-1]+a[i-1][j]-a[i-1][j-1]);
            printf("%d",a[i][j]%2);
        }
        printf("\n");
    }
return 0;
}
