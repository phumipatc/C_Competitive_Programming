/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > p[160010];
int r,c,countt;
int stone[410][410],mark[410][410],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
void dfs(int i,int j){
    mark[i][j] = 1;
    countt++;
    int ni,nj;
    for(int k=0;k<4;k++){
        ni = i+dir[0][k];
        nj = j+dir[1][k];
        if(ni<1 || nj<1 || ni>r || nj>c)    continue;
        if(stone[ni][nj])                   continue;
        if(mark[ni][nj])                    continue;
        dfs(ni,nj);
    }
}
stack<int > st;
int main(){
    int q,ni,nj,ch;
    scanf("%d %d %d",&r,&c,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&p[i].first,&p[i].second);
        p[i].first++,p[i].second++;
        stone[p[i].first][p[i].second] = 1;
    }
    for(int i=1;i<=r;i++){
        if(!mark[i][1] && !stone[i][1])
            dfs(i,1);
        if(!mark[i][c] && !stone[i][c])
            dfs(i,c);
    }
    for(int j=1;j<=c;j++){
        if(!mark[1][j]  && !stone[1][j])
            dfs(1,j);
        if(!mark[r][j] && !stone[r][j])
            dfs(r,j);
    }
    st.push(countt);
    for(int i=q;i>1;i--){
        stone[p[i].first][p[i].second] = 0;
        ch = 0;
        for(int k=0;k<4;k++){
            ni = p[i].first+dir[0][k];
            nj = p[i].second+dir[1][k];
            if(mark[ni][nj] || ni == 0 || nj == 0 || ni == r+1 || nj == c+1)
                ch = 1;
        }
        if(ch)  dfs(p[i].first,p[i].second);
        st.push(countt);
    }
    while(!st.empty()){
        printf("%d\n",st.top());
        st.pop();
    }
	return 0;
}
