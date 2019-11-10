/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],sol[100100];
int find_root(int a){
    if(p[a] == a)   return a;
    else            return p[a] = find_root(p[a]);
}
int main(){
    int n,m,u,v,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        p[i] = i;
        scanf("%d",&sol[i]);
    }
    while(m--){
        scanf("%d %d",&u,&v);
        ru = find_root(u);
        rv = find_root(v);
        if(ru == rv){
            printf("-1\n");
        }else if(sol[ru]>sol[rv]){
            sol[ru]+=sol[rv]/2;
            p[rv] = ru;
        }else if(sol[rv]>sol[ru]){
            sol[rv]+=sol[ru]/2;
            p[ru] = rv;
        }else if(ru<rv)
    }
	return 0;
}
