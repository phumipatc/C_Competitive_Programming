/*
    TASK:
    AUTHOR:
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector<int> g[1100];
queue<int> que;
int count[1100],visit[1100];
int main(void){
    int n,m,q,i,r,s,ch,now;
    memset(count,0,sizeof(count));
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
        count[r]++;
    }
    while(q--){
        scanf("%d %d",&r,&s);
        memset(visit,0,sizeof(visit));
        ch=0;
        que.push(r);
        while(!que.empty()){
            now=que.front();
            que.pop();
            if(now==s){
                ch=1;
                break;
            }
            for(i=0;i<count[now];i++){
                if(!visit[g[now][i]]){
                        visit[g[now][i]]=1;
                        que.push(g[now][i]);
                }
            }
        }
        printf((ch)?"Yes\n":"No\n");
        while(!que.empty())
            que.pop();
    }
return 0;
}
/*
5 5 3
1 2
2 3
1 4
4 5
3 4
*/
