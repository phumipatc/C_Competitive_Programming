/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110][110],r[110],c[110];
int main(){
    int q,n,m,minn,maxx,ch;
    scanf("%d",&q);
    for(int qq=1;qq<=q;qq++){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                r[i] = max(r[i],a[i][j]);
                c[j] = max(c[j],a[i][j]);
            }
        }
        ch = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                minn = min(r[i],c[j]);
                maxx = max(r[i],c[j]);
                if(a[i][j]>=minn && a[i][j]<=maxx)  continue;
                else                                ch = 0;
            }
        }
        printf("Case #%d: ",qq);
        if(ch)  printf("YES\n");
        else    printf("NO\n");
        memset(r,0,sizeof r);
        memset(c,0,sizeof c);
    }
	return 0;
}
