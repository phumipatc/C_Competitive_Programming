/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A pos[910];
int p[910],a[32][32],num[910],dir[2][4]={{-1,1,0,0},{0,0,1,-1}};
int find_root(int now){
    if(p[now] == now)   return now;
    else                return p[now] = find_root(p[now]);
}
int main(){
    int n,m,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            pos[a[i][j]] = {i,j};
        }
    }
    int ans = 0;
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++) p[j] = j,num[j] = 1;
        for(int j=i;j<=n*m;j++){
            for(int k=0;k<4;k++){
                int ni = pos[j].i+dir[0][k],nj = pos[j].j+dir[1][k];
                if(ni<1 || nj<1 || ni>n || nj>m)    continue;
                if(a[ni][nj]<i || a[ni][nj]>j)      continue;
                ru = find_root(j),rv = find_root(a[ni][nj]);
                if(ru == rv)    continue;
                if(ru>rv)   p[ru] = rv,num[rv]+=num[ru];
                else        p[rv] = ru,num[ru]+=num[rv];
            }
            if(num[i] == j-i+1) ans++;
        }
    }
    printf("%d\n",ans);
	return 0;
}
