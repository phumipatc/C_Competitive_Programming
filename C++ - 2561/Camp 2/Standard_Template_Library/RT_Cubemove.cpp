/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x<o.x;
        else        return y<o.y;
    }
};
A a[10010];
int qs[110][110];
int main(){
    int n,m,ans = 1e9,sum;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a[i].x,&a[i].y);
        qs[a[i].x][a[i].y] = 1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=i;k<=n;k++){
                for(int l=j;l<=n;l++){
                    if((k-i+1)*(l-j+1)!=m)  continue;
                    sum = qs[k][l]-qs[k][j-1]-qs[i-1][l]+qs[i-1][j-1];
                    ans = min(ans,m-sum);
                }
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
