/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[1005],n;
void dfs(int now){
    if(now>=(n+1)/2 && now<=n)  return ;
    dfs(now*2);
    dfs(now*2+1);
    tree[now] = min(tree[now*2],tree[now*2+1]);
    tree[now*2]-=tree[now];
    tree[now*2+1]-=tree[now];
}
int main(){
    int sum = 0;
    scanf("%d",&n);
    for(int i=(n+1)/2;i<=n;i++)
        scanf("%d",&tree[i]);
    dfs(1);
    for(int i=1;i<=n;i++)
        sum+=tree[i];
    printf("%d\n",sum);
	return 0;
}
