/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int in[50010],out[50010];
int main(){
    int q,a,b,c,n,m,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&u,&v);
            out[u]++,in[v]++;
        }
        a = b = c = 0;
        for(int i=1;i<=n;i++){
            if(in[i]+1 == out[i])       a++;
            else if(in[i] == out[i]+1)  b++;
            else if(in[i] != out[i])    c++;
        }
        if(c || a>1 || b>1) printf("No\n");
        else                printf("Yes\n");
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
    }
	return 0;
}
