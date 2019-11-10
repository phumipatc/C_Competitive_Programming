/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100010],sol[100010];
int fr(int i){
    if(p[i] == i)   return i;
    else            return p[i] = fr(p[i]);
}
int main(){
    int n,m,u,v,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d\n",&sol[i]);
        p[i] = i;
    }
    while(m--){
        scanf("%d %d",&u,&v);
        ru = fr(u);
        rv = fr(v);
        if(ru == rv)    printf("-1\n");
        else if(sol[ru]>sol[rv]){
            printf("%d\n",ru);
            sol[ru]+=(sol[rv]/2);
            p[rv] = ru;
        }else if(sol[rv]>sol[ru]){
            printf("%d\n",rv);
            sol[rv]+=(sol[ru]/2);
            p[ru] = rv;
        }else if(ru<rv){
            printf("%d\n",ru);
            sol[ru]+=(sol[rv]/2);
            p[rv] = ru;
        }else if(rv<ru){
            printf("%d\n",rv);
            sol[rv]+=(sol[ru]/2);
            p[ru] = rv;
        }
    }
	return 0;
}
