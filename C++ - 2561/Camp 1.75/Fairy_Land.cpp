/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int find_root(int a){
    if(p[a] == a)   return a;
    else            return p[a] = find_root(p[a]);
}
int main(){
    int n,m,u,v,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        p[i] = i;
    while(m--){
        scanf("%d %d",&u,&v);
        ru = find_root(u);
        rv = find_root(v);
        p[ru] = rv;
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d %d",&u,&v);
        ru = find_root(u);
        rv = find_root(v);
        if(ru == rv)    printf("YES\n");
        else            printf("NO\n");
    }
	return 0;
}
