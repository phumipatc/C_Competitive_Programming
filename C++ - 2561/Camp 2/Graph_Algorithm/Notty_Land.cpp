/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
stack<int > st;
int num[100010],low[100010],gr = 1,onstack[100010],comp[100010],countt = 1;
void dfs(int now){
    num[now] = low[now] = gr++;
    onstack[now] = 1;
    st.push(now);
    for(auto x:g[now]){
        if(!num[x]){
            dfs(x);
            low[now] = min(low[now],low[x]);
        }else if(onstack[x]){
            low[now] = min(low[now],num[x]);
        }
    }
    if(num[now] == low[now]){
        while(!st.empty() && st.top()!=now){
            onstack[st.top()] = 0;
            comp[st.top()] = countt;
            st.pop();
        }
        comp[now] = countt++;
        onstack[now] = 0;
        st.pop();
    }
}
int main(){
    int n,m,k,u,v,temp;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        while(temp--){
            scanf("%d",&v);
            g[i].push_back(v);
        }
    }
    for(int i=1;i<=n;i++){
        if(!num[i]){
            dfs(i);
        }
    }
    while(k--){
        scanf("%d %d",&u,&v);
        if(comp[u] == comp[v])  printf("yes\n");
        else                    printf("no\n");
    }
	return 0;
}
