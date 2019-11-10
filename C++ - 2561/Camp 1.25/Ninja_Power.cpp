/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,mem[1<<22],po[1<<22],group[1<<22];
int dfs(int now){
    if(now>=n)          return 0;
    if(mem[now]!=-1)    return mem[now];
    return mem[now] = po[now]+dfs((now*2)+1)+dfs((now*2)+2);
}
int main(){
    int q,sum = 0;
    scanf("%d",&n);
    memset(mem,-1,sizeof mem);
    for(int i=0;i<n;i++){
        scanf("%d",&po[i]);
        sum+=po[i];
    }
    printf("%d\n",sum);
    scanf("%d",&q);
    int a,b;
    while(q--){
        scanf("%d %d",&a,&b);
        if(dfs(a)>dfs(b))           printf("%d>%d\n",a,b);
        else if(dfs(a) == dfs(b))   printf("%d=%d\n",a,b);
        else if(dfs(a)<dfs(b))      printf("%d<%d\n",a,b);
    }
	return 0;
}
