/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1001000],coin[12];
int main(){
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
        mic[i]=1<<25;
    for(i=0;i<n;i++)
        scanf("%d",&coin[i]);
    for(i=1;i<=m;i++){
        for(j=0;j<n;j++)
            if(i>=coin[j])
                mic[i]=min(mic[i-coin[j]]+1,mic[i]);
    }
    if(mic[m]!=1<<25)
        printf("%d\n",mic[m]);
    else
        printf("0\n");
return 0;
}
