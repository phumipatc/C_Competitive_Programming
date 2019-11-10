/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],col[100005],in[100005];
void dfs(int now,int c){
    if(col[now])    return ;
    col[now] = c;
    in[a[now]]--;
    if(!in[a[now]] || c == 1) dfs(a[now],3-c);
}
int main(){
    int q,n,ans;
    cin >> q;
    while(q--){
        ans = 0;
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i],in[a[i]]++;
        for(int i=1;i<=n;i++)
            if(!col[i] && !in[i])
                dfs(i,1);
        for(int i=1;i<=n;i++)
            if(!col[i])
                dfs(i,2);
        for(int i=1;i<=n;i++){
            if(col[i] == 2)
                ans++;
            in[i] = col[i] = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
