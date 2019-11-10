/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,t;
};
A now;
char a[310][310];
int laser[310][310][4],dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
vector<A > coor;
queue<A > que;
int dis[310][310][4];
int main(){
    int q,r,c,sti,stj,eni,enj,temp,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j] == 'S')          sti = i,stj = j,a[i][j] = '.';
                else if(a[i][j] == 'E')     eni = i,enj = j;
                if(a[i][j] == '-')          coor.push_back({i,j,0});
                else if(a[i][j] == '\\')    coor.push_back({i,j,1});
                else if(a[i][j] == '|')     coor.push_back({i,j,2});
                else if(a[i][j] == '/')     coor.push_back({i,j,3});
            }
        }
        for(int k=0;k<4;k++){
            for(auto x:coor){
                temp = (x.t+k)%4;
                laser[x.i][x.j][k] = 1;
                if(temp == 0){
                    i = x.i,j = x.j-1;
                    while(j>0){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        j--;
                    }
                    i = x.i,j = x.j+1;
                    while(j<=c){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        j++;
                    }
                }else if(temp == 1){
                    i = x.i-1,j = x.j-1;
                    while(i>0 && j>0){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i--,j--;
                    }
                    i = x.i+1,j = x.j+1;
                    while(i<=r && j<=c){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i++,j++;
                    }
                }else if(temp == 2){
                    i = x.i-1,j = x.j;
                    while(i>0 && j>0){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i--;
                    }
                    i = x.i+1,j = x.j;
                    while(i<=r && j<=c){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i++;
                    }
                }else if(temp == 3){
                    i = x.i-1,j = x.j+1;
                    while(i>0 && j<=c){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i--,j++;
                    }
                    i = x.i+1,j = x.j-1;
                    while(i<=r && j>0){
                        if(a[i][j] != '.')  break;
                        laser[i][j][k] = 1;
                        i++,j--;
                    }
                }
            }
        }
        que.push({sti,stj,0});
        dis[sti][stj][0] = 1;
        int ch = 1;
        while(!que.empty()){
            now = que.front();
            que.pop();
            if(now.i == eni && now.j == enj){
                printf("%d\n",now.t);
                ch = 0;
                break;
            }
            for(int k=0;k<4;k++){
                int ni = now.i+dir[0][k];
                int nj = now.j+dir[1][k];
                if(ni<1 || nj<1 || ni>r || nj>c)    continue;
                if(a[ni][nj] == '#')                continue;
                if(laser[ni][nj][(now.t+1)%4])      continue;
                if(dis[ni][nj][(now.t+1)%4])        continue;
                dis[ni][nj][(now.t+1)%4] = 1;
                que.push({ni,nj,now.t+1});
            }
        }
        if(ch)  printf("-1\n");
        while(!que.empty()) que.pop();
        coor.clear();
        memset(laser,0,sizeof laser);
        memset(dis,0,sizeof dis);
    }
	return 0;
}
