/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,countt;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
char str[2100],str2[2100];
int dp[2100][2100],path[2100][2100],p[30];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<26;i++)
        scanf("%d",&p[i]);
    scanf(" %s %s",str+1,str2+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                path[i][j] = 4;
            }else if(dp[i-1][j]>dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                path[i][j] = 1;
            }else if(dp[i][j-1]>dp[i-1][j]){
                dp[i][j] = dp[i][j-1];
                path[i][j] = 2;
            }else{
                dp[i][j] = dp[i-1][j];
                path[i][j] = 4;
            }
        }
    }
    printf("%d\n",dp[n][m]);
    int ans = -1e9;
    heap.push({n,m,0,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.countt == dp[n][m]){
            ans = max(ans,now.w);
            continue;
        }
        if(path[now.i][now.j] == 1){
            heap.push({now.i-1,now.j,now.w,now.countt});
        }else if(path[now.i][now.j] == 2){
            heap.push({now.i,now.j-1,now.w,now.countt});
        }else if(path[now.i][now.j] == 3){
            heap.push({now.i-1,now.j,now.w,now.countt});
            heap.push({now.i,now.j-1,now.w,now.countt});
        }else{
            heap.push({now.i-1,now.j-1,now.w+p[str[now.i]-'a'],now.countt+1});
        }
    }
    printf("%d\n",ans);
    return 0;
}
