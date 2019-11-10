/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
};
A now;
queue<A > que;
char a[310][310];
int mark[310][310][4],dis[310][310][4],dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
int main(){
    int q,n,m,sti,stj,eni,enj,ti,tj,ni,nj;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j] == 'S'){
                    sti = i,stj = j;
                    a[i][j] = '.';
                }else if(a[i][j] == 'E'){
                    eni = i,enj = j;
                }else if(a[i][j] == '#'){
                    for(int k=0;k<4;k++)
                        mark[i][j][k] = 1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j] == '-'){
                    for(int k=0;k<4;k++)
                        mark[i][j][k] = 1;
                    //0
                    tj = j-1;
                    while(tj>0 && a[i][tj] == '.')   mark[i][tj][0] = 1,tj--;
                    tj = j+1;
                    while(tj<=m && a[i][tj] == '.')  mark[i][tj][0] = 1,tj++;
                    //1
                    ti = i-1,tj = j-1;
                    while(ti>0 && tj>0 && a[ti][tj] == '.')     mark[ti][tj][1] = 1,ti--,tj--;
                    ti = i+1,tj = j+1;
                    while(ti<=n && tj<=m && a[ti][tj] == '.')   mark[ti][tj][1] = 1,ti++,tj++;
                    //2
                    ti = i-1;
                    while(ti>0 && a[ti][j] == '.')  mark[ti][j][2] = 1,ti--;
                    ti = i+1;
                    while(ti<=n && a[ti][j] == '.') mark[ti][j][2] = 1,ti++;
                    //3
                    ti = i-1,tj = j+1;
                    while(ti>0 && tj<=m && a[ti][tj] == '.')    mark[ti][tj][3] = 1,ti--,tj++;
                    ti = i+1,tj = j-1;
                    while(ti<=n && tj>0 && a[ti][tj] == '.')    mark[ti][tj][3] = 1,ti++,tj--;
                }else if(a[i][j] == '\\'){
                    for(int k=0;k<4;k++)
                        mark[i][j][k] = 1;
                    //3
                    tj = j-1;
                    while(tj>0 && a[i][tj] == '.')   mark[i][tj][3] = 1,tj--;
                    tj = j+1;
                    while(tj<=m && a[i][tj] == '.')  mark[i][tj][3] = 1,tj++;
                    //0
                    ti = i-1,tj = j-1;
                    while(ti>0 && tj>0 && a[ti][tj] == '.')     mark[ti][tj][0] = 1,ti--,tj--;
                    ti = i+1,tj = j+1;
                    while(ti<=n && tj<=m && a[ti][tj] == '.')   mark[ti][tj][0] = 1,ti++,tj++;
                    //1
                    ti = i-1;
                    while(ti>0 && a[ti][j] == '.')  mark[ti][j][1] = 1,ti--;
                    ti = i+1;
                    while(ti<=n && a[ti][j] == '.') mark[ti][j][1] = 1,ti++;
                    //2
                    ti = i-1,tj = j+1;
                    while(ti>0 && tj<=m && a[ti][tj] == '.')    mark[ti][tj][2] = 1,ti--,tj++;
                    ti = i+1,tj = j-1;
                    while(ti<=n && tj>0 && a[ti][tj] == '.')    mark[ti][tj][2] = 1,ti++,tj--;
                }else if(a[i][j] == '|'){
                    for(int k=0;k<4;k++)
                        mark[i][j][k] = 1;
                    //2
                    tj = j-1;
                    while(tj>0 && a[i][tj] == '.')   mark[i][tj][2] = 1,tj--;
                    tj = j+1;
                    while(tj<=m && a[i][tj] == '.')  mark[i][tj][2] = 1,tj++;
                    //3
                    ti = i-1,tj = j-1;
                    while(ti>0 && tj>0 && a[ti][tj] == '.')     mark[ti][tj][3] = 1,ti--,tj--;
                    ti = i+1,tj = j+1;
                    while(ti<=n && tj<=m && a[ti][tj] == '.')   mark[ti][tj][3] = 1,ti++,tj++;
                    //0
                    ti = i-1;
                    while(ti>0 && a[ti][j] == '.')  mark[ti][j][0] = 1,ti--;
                    ti = i+1;
                    while(ti<=n && a[ti][j] == '.') mark[ti][j][0] = 1,ti++;
                    //1
                    ti = i-1,tj = j+1;
                    while(ti>0 && tj<=m && a[ti][tj] == '.')    mark[ti][tj][1] = 1,ti--,tj++;
                    ti = i+1,tj = j-1;
                    while(ti<=n && tj>0 && a[ti][tj] == '.')    mark[ti][tj][1] = 1,ti++,tj--;
                }else if(a[i][j] == '/'){
                    for(int k=0;k<4;k++)
                        mark[i][j][k] = 1;
                    //1
                    tj = j-1;
                    while(tj>0 && a[i][tj] == '.')   mark[i][tj][1] = 1,tj--;
                    tj = j+1;
                    while(tj<=m && a[i][tj] == '.')  mark[i][tj][1] = 1,tj++;
                    //2
                    ti = i-1,tj = j-1;
                    while(ti>0 && tj>0 && a[ti][tj] == '.')     mark[ti][tj][2] = 1,ti--,tj--;
                    ti = i+1,tj = j+1;
                    while(ti<=n && tj<=m && a[ti][tj] == '.')   mark[ti][tj][2] = 1,ti++,tj++;
                    //3
                    ti = i-1;
                    while(ti>0 && a[ti][j] == '.')  mark[ti][j][3] = 1,ti--;
                    ti = i+1;
                    while(ti<=n && a[ti][j] == '.') mark[ti][j][3] = 1,ti++;
                    //0
                    ti = i-1,tj = j+1;
                    while(ti>0 && tj<=m && a[ti][tj] == '.')    mark[ti][tj][0] = 1,ti--,tj++;
                    ti = i+1,tj = j-1;
                    while(ti<=n && tj>0 && a[ti][tj] == '.')    mark[ti][tj][0] = 1,ti++,tj--;
                }
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=0;k<4;k++)
                    dis[i][j][k] = 1e9;
        que.push({sti,stj,0});
        dis[sti][stj][0] = 0;
        int ch = 0;
        while(!que.empty()){
            now = que.front();
            que.pop();
            if(now.i == eni && now.j == enj){
                printf("%d\n",dis[eni][enj][now.w%4]);
                ch = 1;
                break;
            }
            for(int k=0;k<4;k++){
                ni = now.i+dir[0][k];
                nj = now.j+dir[1][k];
                if(ni<1 || nj<1 || ni>n || nj>m)    continue;
                if(mark[ni][nj][(now.w+1)%4])       continue;
                if(dis[ni][nj][(now.w+1)%4]!=1e9)   continue;
                dis[ni][nj][(now.w+1)%4] = now.w+1;
                que.push({ni,nj,now.w+1});
            }
        }
        if(!ch) printf("-1\n");
        while(!que.empty()) que.pop();
        memset(mark,0,sizeof mark);
    }
	return 0;
}
/*
3
2 3
S-#
.E.
1 5
S..E/
5 5
S....
.....
.-|..
.|-..
....E
*/
