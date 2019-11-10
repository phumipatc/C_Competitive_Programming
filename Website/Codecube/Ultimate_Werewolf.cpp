/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int target[100005],col[100005],in[100005];
void dfs(int now,int c){
    if(col[now])    return ;
    col[now] = c;
    in[target[now]]--;
    if(!in[target[now]] || c == 1)
        dfs(target[now],3-c);
}
int main(){
    int q,n,ans;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&target[i]);
            in[target[i]]++;
        }
        for(int i=1;i<=n;i++)
            if(!col[i] && !in[i])
                dfs(i,1);
        for(int i=1;i<=n;i++)
            if(!col[i])
                dfs(i,2);
        for(int i=1;i<=n;i++){
            if(col[i] == 2)
                ans++;
            col[i] = in[i] = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}
