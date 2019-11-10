/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[300100];
int a[300100],mark[300100],group[300100],num = 0;
void dfs(int now){
    if(mark[now])   return ;
    mark[now] = 1;
    group[num]+=a[now];
    for(auto &x:g[now])
        dfs(x);
}
int main(){
    int n,m,u,v,now,idx,opr;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            dfs(i);
            num++;
        }
    }
    sort(group,group+num);
    for(int i=0;i<num;i++)
        printf("%d\n",group[i]);
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d",&now);
            idx = lower_bound(group,group+num,now)-group;
            if(group[idx] == now)   printf("MEENA\n");
            else                    printf("MAIMEE\n");
        }else if(opr == 2){
            scanf("%d",&now);
        }
    }
	return 0;
}
