/*
TASK: Up Kahn
LANG: C++
AUTHOR: PeaTT~
*/
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int> h;
vector<int> a[100100];

int count[100100],size[100100],ans[100100];
int main(){
    int i,j,n,m,u,v,top=0,q;
    scanf("%d",&q);
    while(q--){
        top=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)   size[i]=count[i]=0;
        for(i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            a[u].push_back(v);  size[u]++;
            count[v]++;
        }
        for(i=1;i<=n;i++){
            if(count[i]==0){
                h.push(-i);
            }
        }
        while(!h.empty()){
            v=-h.top(); h.pop();
            ans[top++]=v;
            for(j=0;j<size[v];j++){
                count[a[v][j]]--;
                if(count[a[v][j]]==0){
                    h.push(-a[v][j]);
                }
            }
        }
		//printf("%d\n",top);
        if(top==n){
            printf("Yes ");
            for(i=0;i<top;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }else   printf("No\n");
        while(!h.empty())   h.pop();
        for(i=1;i<=n;i++)   a[i].clear();
    }
    return 0;
}
