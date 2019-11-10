/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[21],p[21][21],n,ans;
void permute(int now){
    if(now == n+1){
        ans++;
        return ;
    }
    permute(now+1);
    int ch = 1;
    for(int i=1;i<now;i++){
        if(mark[i] && p[i][now] == 1){
            ch = 0;
            break;
        }
    }
    if(ch){
        mark[now] = 1;
        permute(now+1);
        mark[now] = 0;
    }
}
int main(){
    int m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        p[a][b] = p[b][a] = 1;
    }
    permute(1);
    printf("%d\n",ans);
    return 0;
}
