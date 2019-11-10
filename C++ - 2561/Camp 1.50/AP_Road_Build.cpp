/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
A need[250100],have[250100];
int p[300100];
int find_root(int n){
    if(p[n] == n)   return n;
    else            return p[n] = find_root(p[n]);
}
int main(){
    int q,v,m,e,ru,rv,l,r,mid,ch;
    scanf("%d",&q);
    for(int k=1;k<=q;k++){
        scanf("%d %d %d",&v,&e,&m);
        for(int i=1;i<=m;i++)
            scanf("%d %d",&need[i].u,&need[i].v);
        for(int i=1;i<=e;i++)
            scanf("%d %d",&have[i].u,&have[i].v);
        l = 1,r = e+1;
        while(l<r){
            mid = (l+r)/2,ch = 0;
            for(int i=1;i<=v;i++)   p[i] = i;
            for(int i=1;i<=mid;i++){
                ru = find_root(have[i].u);
                rv = find_root(have[i].v);
                if(ru!=rv)  p[ru] = rv;
            }
            for(int i=1;i<=m;i++){
                ru = find_root(need[i].u);
                rv = find_root(need[i].v);
                if(ru!=rv)  ch = 1;
            }
            if(ch)  l = mid+1;
            else    r = mid;
        }
        if(r>e) printf("C#%d: -1\n",k);
        else    printf("C#%d: %d\n",k,r);
    }
	return 0;
}
