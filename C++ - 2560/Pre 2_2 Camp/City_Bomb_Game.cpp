/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int now,player;
    bool operator < (const A&o) const{
        if(now!=o.now)  return now<o.now;
        else            return player<o.player;
    }
};
priority_queue< A> heap;
vector< int> g[1100];
int n,k,mark[1100],ans[1100];
void dfs(int now,int state){
//    printf("%d %d\n",now,state);
    mark[now]=state;
    for(int i=0;i<g[now].size();i++)
        if(mark[g[now][i]]==0)
            dfs(g[now][i],state+1);
    return ;
}

int main(){
    int a,b,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=1;i<=n;i++)
        sort(g[i].begin(),g[i].end());
    dfs(k,1);
    for(i=1;i<=n;i++){
        if(g[i].size()==1){
            if(mark[i]%2==0)
                heap.push({i,1});
            else
                heap.push({i,2});
        }
    }
    while(!heap.empty()){
        A temp=heap.top();
        heap.pop();
        if(temp.player==1){
            ans[temp.now]=max(1,ans[temp.now]);
            for(i=0;i<g[temp.now].size();i++)
                if(mark[g[temp.now][i]]<mark[temp.now])
                    heap.push({g[temp.now][i],ans[temp.now]});
        }else if(temp.player==2){
            if(g[temp.now].size()>2){
                if(mark[temp.now]%2==0){
                    ans[temp.now]=2;
                    for(i=0;i<g[temp.now].size();i++)
                        if(mark[g[temp.now][i]]<mark[temp.now])
                            heap.push({g[temp.now][i],ans[temp.now]});
                }
            }else if(temp.now!=k){
                ans[temp.now]=2;
                for(i=0;i<g[temp.now].size();i++)
                    if(mark[g[temp.now][i]]<mark[temp.now])
                        heap.push({g[temp.now][i],ans[temp.now]});
            }
        }
    }
//    for(i=1;i<=n;i++)
//        printf("%d\n",ans[i]);
    if(ans[k]==1){
        printf("First player wins traveling to city ");
        for(i=0;i<g[k].size();i++){
            if(ans[g[k][i]]==1){
                printf("%d\n",g[k][i]);
                break;
            }
        }
    }else
        printf("First player loses\n");
    return 0;
}
/*
4 3
3 2
3 1
1 4

7 3
3 1
1 4
4 5
5 2
2 6
5 7
*/
