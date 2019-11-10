/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#include<rescuelib.h>
// #include<rescuelib.cpp>
using namespace std;
typedef long long LL;
const int INF = 1e9;
int dis[1010][1010],ret[4];
int dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
set<pair<int ,int > > sett[2];
set<pair<int ,int > > ::iterator it;
queue<pair<int ,int > > que;
pair<int ,int > p[4],now;
void setdisINF(int r,int c){
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            dis[i][j] = INF;
}
// void get_size(int &r,int &c){
//     r = c = 10;
// }
// int drop_robot(int i,int j){
//     int d;
//     cin >> d;
//     return d;
// }
// void answer(int i,int j){
//     cout << i << " " << j << "\n";
// }
int main(){
    int r,c,countt = 0,idx = 0,ii,jj,num;
    get_size(r,c);
    ret[0] = drop_robot(1,1),p[0] = {1,1};
    ret[1] = drop_robot(1,c),p[1] = {1,c};
    ret[2] = drop_robot(r,1),p[2] = {r,1};
    ret[3] = drop_robot(r,c),p[3] = {r,c};
    for(int i=0;i<4;i++)
        countt+=(ret[i] == -1);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            sett[1].insert({i,j});
    if(countt == 0 || countt == 2){
        for(int i=0;i<4;i++){
            if(ret[i] == -1)    continue;
            setdisINF(r,c);
            sett[idx].clear();
            que.push(p[i]);
            dis[p[i].first][p[i].second] = 0;
            while(!que.empty()){
                now = que.front();
                que.pop();
                if(dis[now.first][now.second] == ret[i]){
                    it = sett[(idx+1)%2].find(now);
                    if(*it!=now)    continue;
                    sett[idx].insert(now);
                    continue;
                }
                // printf("%d %d\n",now.first,now.second);
                for(int k=0;k<4;k++){
                    ii = now.first+dir[0][k];
                    jj = now.second+dir[1][k];
                    if(ii>r || ii<1 || jj>c || jj<1)                continue;
                    if(dis[ii][jj]<=dis[now.first][now.second]+1)   continue;
                    dis[ii][jj] = dis[now.first][now.second]+1;
                    que.push({ii,jj});
                }
            }
            while(!que.empty()) que.pop();
            // for(auto x:sett[idx])
            //     printf("%d %d\n",x.first,x.second);
            idx++,idx%=2;
        }
        idx++,idx%=2;
        it = sett[idx].begin();
        answer(it->first,it->second);
        return 0;
    }
    return 0;
}