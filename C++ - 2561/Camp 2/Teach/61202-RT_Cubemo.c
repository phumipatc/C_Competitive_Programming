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
    sort(a+1,a+m+1);
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            if(a[i].x == a[j].x && a[i].y == a[j].y)    continue;
            if(m<(a[j].x-a[i].x+1)*(a[j].y-a[i].y+1))   continue;
            if(m == (a[j].x-a[i].x+1)*(a[j].y-a[i].y+1)){
                sum = (qs[a[j].x][a[j].y]-qs[a[i].x-1][a[j].y]-qs[a[j].x][a[i].y-1]+qs[a[i].x-1][a[i].y-1]);
                ans = min(ans,m-sum);
            }else{
                sum = m-((a[j].x-a[i].x+1)*(a[j].y-a[i].y+1));
                if(sum%(a[j].y-a[i].y))
            }
        }
    }
    if(ans == 1e9)  printf("%d\n",m-1);
    else            printf("%d\n",ans);
	return 0;
}
