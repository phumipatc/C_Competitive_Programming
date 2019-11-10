/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1500][1500];
int main(){
    int n,i,j,m;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&i,&j);
        a[i+1][j+1]++;
    }
    for(i=1;i<=1001;i++){
        for(j=1;j<=1001;j++){
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    while(m--){
        int x,y,k,r,s;
        scanf("%d %d %d",&x,&y,&k);
        x++,y++;
        i=(x-k<1)?1:x-k;
        j=(y-k<1)?1:y-k;
        r=(x+k>1001)?1001:x+k;
        s=(y+k>1001)?1001:y+k;
        printf("%d\n",a[r][s]-a[r][j-1]-a[i-1][s]+a[i-1][j-1]);
    }
    return 0;
}
