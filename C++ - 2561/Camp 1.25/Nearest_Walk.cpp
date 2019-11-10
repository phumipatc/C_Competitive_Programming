/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,v;
};
A now;
queue< A> que;
char a[1010][1010];
int dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int main(){
    int q,r,c,ch;
    scanf("%d",&q);
    while(q--){
        ch = 0;
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j] == 'A')  a[i][j] = '#',que.push({i,j,0});
            }
        }
        while(!que.empty()){
            now = que.front();
            que.pop();
            if(a[now.i][now.j] == 'B'){
                ch = 1;
                break;
            }
            for(int k=0;k<4;k++){
                int ni = now.i+dir[0][k];
                int nj = now.j+dir[1][k];
                if(ni<1 || nj<1 || ni>r || nj>c)    continue;
                if(a[ni][nj] == '#')                continue;
                if(a[ni][nj] != 'B')                a[ni][nj] = '#';
                que.push({ni,nj,now.v+1});
            }
        }
        if(ch)  printf("%d\n",now.v);
        else    printf("-1\n");
        while(!que.empty()) que.pop();
    }
	return 0;
}
