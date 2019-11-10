/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[10100],mark[10100];
int find_root(int num){
    if(num == p[num])   return num;
    else                return p[num] = find_root(p[num]);
}
int main(){
    int n,m,ans = -1,num,now,root;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)   p[i] = i;
    while(n--){
        scanf("%d",&num);
        if(num == 0)    ans++;
        else{
            scanf("%d",&root);
            mark[root] = 1;
            num--;
            while(num--){
                scanf("%d",&now);
                mark[now] = 1;
                p[find_root(now)] = p[find_root(root)];
            }
        }
    }
    for(int i=1;i<=m;i++)
        if(p[i] == i && mark[i] == 1)
            ans++;
    printf("%d\n",ans);
	return 0;
}
