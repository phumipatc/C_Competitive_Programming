/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100010];
int find_root(int i){
    if(p[i] == i)   return i;
    else            return p[i] = find_root(p[i]);
}
int main(){
    int n,q,u,v,ru,rv;
    char opr;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)   p[i] = i;
    while(q--){
        scanf(" %c %d %d",&opr,&u,&v);
        ru = find_root(u);
        rv = find_root(v);
        if(opr == 'q'){
            if(ru == rv)    printf("yes\n");
            else            printf("no\n");
        }else{
            p[ru] = rv;
        }
    }
	return 0;
}
