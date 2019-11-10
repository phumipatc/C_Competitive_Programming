/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[1010][1010];
int main(){
    int i,j,n,m,k,i1,i2,j1,j2;
    scanf("%d %d",&n,&m);
    while(n--){
        scanf("%d %d",&i,&j);
        mic[i+1][j+1]++;
    }
    for(i=1;i<=1001;i++)
        for(j=1;j<=1001;j++)
            mic[i][j]+=mic[i-1][j]+mic[i][j-1]-mic[i-1][j-1];
    while(m--){
        scanf("%d %d %d",&i,&j,&k);
        i1=i+1-k,j1=j+1-k,i2=i+1+k,j2=j+1+k;
        if(i1<1)    i1=1;
        if(j1<1)    j1=1;
        if(i2>1001) i2=1001;
        if(j2>1001) j2=1001;
        printf("%d\n",mic[i2][j2]-mic[i1-1][j2]-mic[i2][j1-1]+mic[i1-1][j1-1]);
    }
return 0;
}
/*
5 2
0 0
0 10
10 0
10 10
5 5
5 5 5
10 10 5
*/
