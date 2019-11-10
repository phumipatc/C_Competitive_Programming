/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[110],c[100100],mark[20000100];
int main(){
    int n,m,k,ans=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            mark[a[i]+b[j]]=1;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(mark[c[i]])  ans++;
    }
    printf("%d\n",ans);
    return 0;
}
/*
4 5 9
1 3 4 5
1 2 6 7 9
1 2 3 4 5 6 7 8 9
*/
