/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A now;
int a[800][800],dir[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
queue< A> que;
int main(){
    int w,h,countt,ans = 0,ni,nj;
    scanf("%d %d",&w,&h);
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(a[i][j] == '*')  continue;
            a[i][j] = '*';
            que.push({i,j});
            countt = 0;
            while(!que.empty()){
                now = que.front();
                que.pop();
                countt++;
                for(int k=0;k<8;k++){
                    ni = now.i+dir[0][k];
                    nj = now.j+dir[1][k];
                    if(ni<1 || nj<1 || ni>h || nj>w)    continue;
                    if(a[ni][nj] == '*')                continue;
                    a[ni][nj] = '*';
                    que.push({ni,nj});
                }
            }
            ans = max(ans,countt);
        }
    }
    printf("%d\n",ans);
	return 0;
}
