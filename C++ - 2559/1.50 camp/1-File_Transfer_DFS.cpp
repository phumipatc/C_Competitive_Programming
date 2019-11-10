/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> g[1100];
int count[1100],visit[1100],r,s,ch;
void start(int now){
    int i;
    if(now==s){
        ch=1;
        return ;
    }
    for(i=0;i<count[now];i++){
        if(!visit[g[now][i]]){
            visit[g[now][i]]=1;
            start(g[now][i]);
        }
    }
}
main(){
    int n,m,q,i;
    memset(count,0,sizeof(count));
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
        count[r]++;
    }
    for(i=0;i<q;i++){
        scanf("%d %d",&r,&s);
        memset(visit,0,sizeof(visit));
        ch=0;
        start(r);
        printf((ch)?"Yes\n":"No\n");
    }
return 0;
}
