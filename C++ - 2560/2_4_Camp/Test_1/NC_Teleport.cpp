/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,dis;
};
vector< int> g[200011];
queue< A> que;
int mark[200011];
int main(){
    int n,a,t,num;
    scanf("%d %d %d",&n,&a,&t);
    for(int i=1;i<=t;i++){
        for(int j=1;j<=a;j++){
            scanf("%d",&num);
            g[num].push_back(i+n);
            g[i+n].push_back(num);
        }
    }
    que.push({1,1});
    while(!que.empty()){
        A now=que.front();
        que.pop();
        if(mark[now.idx])   continue;
        mark[now.idx]=1;
        if(now.idx==n){
            printf("%d\n",(now.dis/2)+1);
            return 0;
        }
        for(int i=0;i<g[now.idx].size();i++)
            que.push({g[now.idx][i],now.dis+1});
    }
    printf("-1\n");
    return 0;
}
