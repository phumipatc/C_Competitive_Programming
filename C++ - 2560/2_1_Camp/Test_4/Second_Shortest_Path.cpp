/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,dis;
    bool operator < (const A&o)const{
        return dis>o.dis;
    }
};
priority_queue< A> h;
vector< A> g[10100];
int dis[10100],mark[10100];
int main(){
    int n,m,st,en,i,u,v,d,ch=-1;
    scanf("%d %d %d %d",&n,&m,&st,&en);
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&d);
        g[u].push_back({v,d});
    }
    memset(dis,-1,sizeof dis);
    h.push({st,0});
    while(!h.empty()){
        A temp=h.top();
//        printf("%d\n",temp.pos);
        h.pop();
        if(mark[temp.pos]>=2 || temp.dis==dis[temp.pos])  continue;
        mark[temp.pos]++;
        dis[temp.pos]=temp.dis;
        if(temp.pos==en && ch!=-1){
            if(temp.dis>ch){
                printf("%d\n",temp.dis);
                return 0;
            }
        }else if(temp.pos==en)
            ch=temp.dis;
        for(i=0;i<g[temp.pos].size();i++)
            h.push({g[temp.pos][i].pos,temp.dis+g[temp.pos][i].dis});
    }
    return 0;
}
/*
3 3
1 3
1 2 1
1 3 3
2 3 1
*/
