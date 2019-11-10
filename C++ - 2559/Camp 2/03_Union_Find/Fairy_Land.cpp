/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[120000];
int root(int n){
    if(p[n]==n)
        return n;
    return p[n]=root(p[n]);
}
int main(){
    int n,m,i,roota,rootb,r,s;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        p[i]=i;
    while(m--){
        scanf("%d %d",&r,&s);
        roota=root(r);
        rootb=root(s);
        p[rootb]=roota;
    }
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        roota=root(a);
        rootb=root(b);
        if(roota==rootb)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
