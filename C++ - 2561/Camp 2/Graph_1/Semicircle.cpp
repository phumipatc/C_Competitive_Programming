/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
};
A a[710];
vector<int > g[710];
int col[710];
int dfs(int now,int c){
    if(col[now] && col[now] == c)   return 1;
    if(col[now] && col[now] != c)   return 0;
    col[now] = c;
    for(auto x:g[now])
        if(!dfs(x,3-c))
            return 0;
    return 1;
}
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].st,&a[i].en);
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i].st<a[j].st && a[i].en<a[j].en && a[i].en>a[j].st) || (a[j].st<a[i].st && a[j].en<a[i].en && a[j].en>a[i].st)){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int countt = 1,ch = 1;
        for(int i=1;i<=n;i++){
            if(col[i])  continue;
            if(!dfs(i,1)){
                ch = 0;
                break;
            }else if(dfs(i,1)){
                countt*=2;
                countt%=1001;
            }
        }
        if(!ch) printf("0\n");
        else    printf("%d\n",countt);
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(col,0,sizeof col);
    }
	return 0;
}
