/*
    TASK:Milk
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
    double w;
    bool operator<(const A &o) const{
        if(w<o.w)
            return true;
        else
            return false;
    }
};
typedef struct A A;
A ar[600000];
int p[100100],h[100100];
int findroot(int i){
    int temp=i,next;
    while(p[i]!=i)
        i=p[i];
    while(temp!=i){
        next=p[temp];
        p[temp]=i;
        temp=next;
    }
    return i;
}
main(){
    int n,m,i,roota,rootb;
    double sum;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d %d %lf",&ar[i].u,&ar[i].v,&ar[i].w);
    sort(ar,ar+m);
    for(i=0;i<=n;i++){
        p[i]=i;
        h[i]=0;
    }
    for(i=0;i<m;i++){
        roota=findroot(ar[i].u);
        rootb=findroot(ar[i].v);
        if(roota!=rootb){
                sum+=ar[i].w;
            if(h[roota]>h[rootb])
                p[rootb]=roota;
            else if(h[rootb]>h[roota])
                p[roota]=rootb;
            else if(h[roota]==h[rootb]){
                p[roota]=rootb;
                h[rootb]++;
            }
        }
    }
    printf("%.3lf\n",sum);
return 0;
}
/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/
