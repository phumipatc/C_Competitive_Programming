/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    double w;
    bool operator <(const A & o) const{
        return w<o.w;
    }
};
A ar[500000];
int P[1100];
int root(int x){
    if(P[x]==x)
        return x;
    return P[x]=root(P[x]);
}
int main(){
    int n,m,a,b,ra,rb,i,coun=0;
    double ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        P[i]=i;
    for(i=0;i<m;i++)
        scanf("%d %d %lf",&ar[i].u,&ar[i].v,&ar[i].w);
    sort(ar,ar+m);
    for(i=0;i<m;i++){
        ra=root(ar[i].u);
        rb=root(ar[i].v);
        if(ra!=rb){
            coun++;
            ans+=ar[i].w;
            P[ra]=rb;
            if(coun==n-1)
                break;
        }
    }
    printf("%.3lf\n",ans);
return 0;
}
