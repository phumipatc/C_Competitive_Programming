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
A now;
queue<A > que;
int a[55][55],turn[55][55];
int dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
int main(){
    int n,m,ch = 1;
    char temp;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&temp);
            if(temp == 'W') a[i][j] = 1;
            else            a[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]) continue;
            memset(turn,0,sizeof turn);
            for(int k=i;k>=1 && a[k][j] == 0;k--){
                turn[k][j] = 1;
                que.push({k,j});
            }
            for(int k=i+1;k<=n && a[k][j] == 0;k++){
                turn[k][j] = 1;
                que.push({k,j});
            }
            for(int k=j-1;k>=1 && a[i][k] == 0;k--){
                turn[i][k] = 1;
                que.push({i,k});
            }
            for(int k=j+1;k<=m && a[i][k] == 0;k++){
                turn[i][k] = 1;
                que.push({i,k});
            }
            while(!que.empty()){
                now = que.front();
                que.pop();
                for(int k=now.i-1;k>=1 && a[k][now.j] == 0;k--)
                    turn[k][now.j] = 1;
                for(int k=now.i+1;k<=n && a[k][now.j] == 0;k++)
                    turn[k][now.j] = 1;
                for(int k=now.j-1;k>=1 && a[now.i][k] == 0;k--)
                    turn[now.i][k] = 1;
                for(int k=now.j+1;k<=m && a[now.i][k] == 0;k++)
                    turn[now.i][k] = 1;
            }
            for(int k=1;k<=n;k++){
                for(int l=1;l<=m;l++){
                    if(a[k][l]) continue;
                    if(!turn[k][l]){
                        // printf("%d %d %d %d\n",i,j,k,l);
                        // for(int x=1;x<=n;x++){
                        //     for(int y=1;y<=m;y++){
                        //         printf("%d ",turn[x][y]);
                        //     }
                        //     cout << endl;
                        // }
                        ch = 0;
                        goto next;
                    }
                }
            }
        }
    }
    next:;
    if(ch)  printf("YES\n");
    else    printf("NO\n");
	return 0;
}
