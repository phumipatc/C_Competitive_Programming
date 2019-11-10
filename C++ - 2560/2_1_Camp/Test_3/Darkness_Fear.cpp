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
        return dis > o.dis;
    }
};
struct B{
    int x,y;
};
char a[10100][10100];
B b[2100];
priority_queue< A> heap;
vector< int> g[2100];
int mark[2100],dis[2100][2100];
int main(){
    int n,m,k,i,j,coun=0,en;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf(" %s",a[i]+1);
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i][j] == 'X'){
                b[coun].x = i;
                b[coun++].y = j;
            }else if(a[i][j] == 'A'){
                heap.push({coun,0});
                b[coun].x = i;
                b[coun++].y = j;
            }else if(a[i][j] == 'B'){
                en = coun;
                b[coun].x = i;
                b[coun++].y = j;
            }
        }
    }
    for(i=0;i<coun;i++){
        for(j=i+1;j<coun;j++){
            if(abs(b[i].x-b[j].x)+abs(b[i].y-b[j].y) <= k){
                g[i].push_back(j);
                g[j].push_back(i);
                dis[i][j]=dis[j][i]=abs(b[i].x-b[j].x)+abs(b[i].y-b[j].y);
            }
        }
    }
    while(!heap.empty()){
        A now=heap.top();
        heap.pop();
        if(mark[now.pos])   continue;
        mark[now.pos]=1;
        if(now.pos==en){
            printf("%d\n",now.dis);
            return 0;
        }
        for(i=0;i<g[now.pos].size();i++){
            heap.push({g[now.pos][i],now.dis+dis[now.pos][g[now.pos][i]]});
        }
    }
    printf("-1\n");
    return 0;
}
/*
4 3 2
X.A
...
X..
.B.
*/
