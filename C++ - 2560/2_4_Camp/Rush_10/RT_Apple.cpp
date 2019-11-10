/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> > que;
pair<int,int> now,nextt;
char str[510][510];
int mark[510][510],dir[2][4]={{1,-1,0,0},{0,0,1,-1}};
int main(){
    int r,c,q,x,y;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        scanf(" %s",str[i]+1);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&x,&y);
        if(str[x][y]=='x'){
            printf("0\n");
            continue;
        }
        que.push(make_pair(x,y));
        mark[x][y]=1;
        while(!que.empty()){
            now=que.front();
            que.pop();
            if(str[now.first][now.second]=='x'){
                printf("%d\n",(((x-now.first)*(x-now.first))+((y-now.second)*(y-now.second))));
                break;
            }
            for(int k=0;k<4;k++){
                nextt.first=now.first+dir[0][k];
                nextt.second=now.second+dir[1][k];
                if(mark[nextt.first][nextt.second])  continue;
                mark[nextt.first][nextt.second]=1;
                que.push(nextt);
            }
        }
        while(!que.empty()) que.pop();
        memset(mark,0,sizeof mark);
        str[x][y]='x';
    }
    return 0;
}
/*
5 5
..x..
....x
.....
.....
.....
*/
