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
A now,nextt;
char a[32][32];
int dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
queue< A>  que;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int j=1;j<=m;j++){
        if(a[1][j] == '.' && a[1][j+1] == '.' && a[2][j] == '.' && a[2][j+1] == '.'){
            a[2][j] = '%';
            que.push({2,j});
        }
    }
    int ch = 0;
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now.i == n){
            ch = 1;
            break;
        }
        if(a[now.i+1][now.j] == '.' && a[now.i+1][now.j+1] == '.'){
            a[now.i+1][now.j] = '%';
            que.push({now.i+1,now.j});
        }
        if(a[now.i][now.j+2] == '.' && a[now.i-1][now.j+2] == '.'){
            a[now.i][now.j+1] = '%';
            que.push({now.i,now.j+1});
        }
        if(a[now.i][now.j-1] == '.' && a[now.i-1][now.j-1] == '.'){
            a[now.i][now.j-1] = '%';
            que.push({now.i,now.j-1});
        }
        if(a[now.i-2][now.j] == '.' && a[now.i-2][now.j+1] == '.'){
            a[now.i-1][now.j] = '%';
            que.push({now.i-1,now.j});
        }
    }
    if(ch)  printf("yes\n");
    else    printf("no\n");
    return 0;
}
