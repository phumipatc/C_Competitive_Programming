/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],mark[200010];
int countt = 0;
void dfs(int now){
    if(mark[now])   return ;
    countt++;
    mark[now] = 1;
    dfs(a[now]);
    mark[now] = countt;
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> a[i];
        for(int i=1;i<=n;i++){
            countt = 0;
            if(!mark[i])	dfs(i);
            printf("%d ",mark[i]);
        }
        printf("\n");
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
Link: https://codeforces.com/contest/1249/problem/B2
*/