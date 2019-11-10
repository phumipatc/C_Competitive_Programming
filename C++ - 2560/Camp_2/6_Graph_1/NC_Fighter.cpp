/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> g[100100];
int mark[100100],mid;
int dfs(int u,int color){
    if(mark[u]==color)                  return 0;
    if(mark[u]!=0 && mark[u]!=color)    return 1;
    mark[u]=color;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i].second>mid)  continue;
        if(dfs(g[u][i].first,3-color)==1)
            return 1;
    }
    return 0;
}
int main(){
    int a,b,i,s,r,ch,p,q;
    scanf("%d %d",&a,&b);
    for(i=1;i<=b;i++){
        scanf("%d %d",&r,&s);
        g[r].push_back(make_pair(s,i));
        g[s].push_back(make_pair(r,i));
    }
    p=1,q=b;
    while(p<q){
        mid=(p+q)/2;
        memset(mark,0,sizeof mark);
        for(i=1,ch=0;i<=a;i++){
            if(mark[i]==0){
                if(dfs(i,1)==1){
                    ch=1;
                    break;
                }
            }
        }
        if(ch==0)   p=mid+1;
        else        q=mid;
    }
    printf("%d\n",p);
	return 0;
}
