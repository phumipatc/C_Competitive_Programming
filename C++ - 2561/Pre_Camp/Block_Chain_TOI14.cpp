/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[1030][1030];
int num[1010],mark[1010];
int main(){
    int t,q,n,u,v,countt;
    scanf("%d %d",&t,&q);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        num[i] = n;
        for(int j=1;j<n;j++){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            g[u][v].push_back(i);
        }
    }
    while(q--){
        scanf("%d",&n);
        memset(mark,0,sizeof mark);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
            if(u>v) swap(u,v);
            for(auto x:g[u][v]){
                if(mark[x] == i-1)  mark[x] = i;
                else                mark[x] = 0;
            }
        }
        countt = 0;
        for(int i=1;i<=t;i++){
            if(mark[i] == n-1 && num[i] == n)
                countt++;
        }
        printf("%d\n",countt);
    }
	return 0;
}
