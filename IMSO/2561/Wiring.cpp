/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100100];
int a[100100],deg[100100];
queue< int> que;
int main(){
    int q,n,num,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            a[num] = i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&num);
            if(num == 0 || a[num] == i)    continue;
            g[a[num]].push_back(i);
            g[i].push_back(a[num]);
            deg[a[num]]++;
            deg[i]++;
        }
        for(int i=1;i<=n;i++){
            if(deg[i] == 1){
                deg[i]--;
                que.push(i);
            }
        }
        while(!que.empty()){
            now = que.front();
            que.pop();
            for(auto &x:g[now]){
                if(deg[x] == 0) continue;
                deg[x]--;
                if(deg[x] == 1)
                    que.push(x);
            }
        }
        int ch = 0;
        for(int i=1;i<=n;i++){
            if(deg[i]!=0)
                ch = 1;
        }
        if(ch)  printf("NO\n");
        else    printf("YES\n");
        memset(a,0,sizeof a);
        memset(deg,0,sizeof deg);
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
