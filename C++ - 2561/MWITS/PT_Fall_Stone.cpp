#include<bits/stdc++.h>
using namespace std;
pair< int,int > opr[160010];
stack<int > ans;
int out[410][410],mark[410][410];
int countt;
int dir[4]={0,0,1,-1},dic[4]={1,-1,0,0};
void dfs(int i,int j){
    if(out[i][j])  return ;
    out[i][j] = 1;
    countt++;
    for(int k=0;k<4;k++){
        if(mark[i+dir[k]][j+dic[k]])    continue;
        if(out[i+dir[k]][j+dic[k]])     continue;
        dfs(i+dir[k],j+dic[k]);
    }
}
int main(){
    int r,c,q;
    scanf("%d %d %d",&r,&c,&q);
    for(int i=0;i<=r+1;i++) out[i][0] = out[i][c+1] = 1;
    for(int j=0;j<=c+1;j++) out[0][j] = out[r+1][j] = 1;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&opr[i].first,&opr[i].second);
        opr[i].first++,opr[i].second++;
        mark[opr[i].first][opr[i].second] = 1;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            for(int k=0;k<4;k++){
                if(mark[i][j])                  continue;
                if(!out[i+dir[k]][j+dic[k]])    continue;
                dfs(i,j);
            }
        }
    }
    ans.push(countt);
    for(int i=q;i>1;i--)
    {
        mark[opr[i].first][opr[i].second] = 0;
        for(int k=0;k<4;k++){
            if(mark[opr[i].first][opr[i].second])               continue;
            if(!out[opr[i].first+dir[k]][opr[i].second+dic[k]]) continue;
            dfs(opr[i].first,opr[i].second);
        }
        ans.push(countt);
    }
    while(!ans.empty()){
        printf("%d\n",ans.top());
        ans.pop();
    }
    return 0;
}
