#include<bits/stdc++.h>
using namespace std;
struct info{
    int to,val;
};
vector <info> v[1010];
queue <info> q;
int mark[1010][2020];
//dis[node][money]
int main(){
    int n,nx,sk,li,lf,lt,lv;
    scanf("%d %d",&n,&nx);
    scanf("%d",&sk);
    for(int i = 1 ; i <= sk ; i++){
        scanf("%d %d",&lf,&lt);
        v[lf].push_back({lt,0});
    }
    scanf("%d",&li);
    for(int i = 1 ; i <= li ; i++){
        scanf("%d %d %d",&lf,&lt,&lv);
        v[lf].push_back({lt,lv});
    }
    int pos,mon;
    scanf("%d %d",&pos,&mon);
    q.push({pos,mon});
    mark[pos][mon] = 1;
    int nownode,nowmon;
    while(!q.empty()){
        nownode = q.front().to;
        nowmon = q.front().val;
        q.pop();
        for(int i = 0 ; i < v[nownode].size() ; i++){
            if(v[nownode][i].val != 0 && nowmon - v[nownode][i].val >= 0){
                //lift
                if(mark[v[nownode][i].to][nowmon - v[nownode][i].val] == 1) continue;
                mark[v[nownode][i].to][nowmon - v[nownode][i].val] = 1;
                q.push({v[nownode][i].to,nowmon - v[nownode][i].val});
            }else{
                if(mark[v[nownode][i].to][nowmon] == 1) continue;
                mark[v[nownode][i].to][nowmon] = 1;
                q.push({v[nownode][i].to,nowmon});
            }
        }
    }
    for(int j = 0 ; j <= mon ; j++){
        for(int i = 1 ; i <= nx ; i++){
            if(mark[i][j]){
                printf("%d",j);
                return 0;
            }
        }
    }
}
