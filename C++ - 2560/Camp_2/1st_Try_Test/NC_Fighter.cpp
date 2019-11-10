#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> vec[100100];
int mark[100100],mid;
int bipartite(int u,int color){
    if(mark[u]==color)  return 0;
    if(mark[u]!=0 && mark[u]!=color)    return 1;
    mark[u]=color;
    for(int i=0;i<vec[u].size();i++){
        if(vec[u][i].second>mid)   continue;
        if(bipartite(vec[u][i].first,3-color)==1)
            return 1;
    }
    return 0;
}
int main(){
    int a,b,i,n,m,l,r,ch;
    scanf("%d %d",&a,&b);
    for(i=1;i<=b;i++){
        scanf("%d %d",&n,&m);
        vec[n].push_back(make_pair(m,i));
        vec[m].push_back(make_pair(n,i));
    }
    l=1;r=b;
    while(l<r){
        mid=(l+r)/2;
        memset(mark,0,sizeof mark);
        for(i=1,ch=0;i<=a;i++){
            if(mark[i]==0){
                if(bipartite(i,1)==1){
                    ch=1;
                    break;
                }
            }
        }
        if(ch==0)      l=mid+1;
        else        r=mid;
    }
    printf("%d",l);
    return 0;
}
/*
6 8
3 4
1 2
5 6
1 6
1 3
4 5
2 4
2 6
*/
