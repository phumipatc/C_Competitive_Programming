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
char a[2005][2005];
int dir[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,1,0,-1,-1}};
queue< A> que;
int main(){
    int n,m,countt = 0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
        scanf(" %s",a[i]+1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == '1'){
                countt++;
                a[i][j] = '0';
                que.push({i,j});
                while(!que.empty()){
                    now = que.front();
                    que.pop();
                    for(int k=0;k<8;k++){
                        nextt.i = now.i+dir[0][k];
                        nextt.j = now.j+dir[1][k];
                        if(a[nextt.i][nextt.j] == '1'){
                            a[nextt.i][nextt.j] = '0';
                            que.push(nextt);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",countt);
    return 0;
}
