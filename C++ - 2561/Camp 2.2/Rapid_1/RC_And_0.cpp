/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],mark[1000010];
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--){
        scanf("%d %d",&u,&v);
        mark[u]++;
        mark[v+1]--;
    }
    for(int i=1;i<=n;i++){
        mark[i]+=mark[i-1];
        if(mark[i]) printf("0 ");
        else        printf("%d ",a[i]);
    }
	return 0;
}
