#include<stdio.h>
#include<stdlib.h>
typedef struct A{
    int u,v,w;
}A;
A g[100010];
int p[100010];
int cmp(const void *a,const void *b){
    A *na = (A *)a;
    A *nb = (A *)b;
    return (na->w)>(nb->w);
}
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    int n,m,ru,rv;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(int i=1;i<=m;i++)
        scanf("%d %d %d",&g[i].u,&g[i].v,&g[i].w);
    qsort(g+1,m,sizeof(A),cmp);
    int sum = 0;
    for(int i=1;i<=m;i++){
        ru = find_root(g[i].u);
        rv = find_root(g[i].v);
        if(ru == rv)    continue;
        p[ru] = rv;
        sum+=g[i].w;
    }
    printf("%d\n",sum);
    return 0;
}