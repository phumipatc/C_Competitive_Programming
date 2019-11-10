/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
    char opr;
};
A a[300005];
map<int,int> mapp;
int in[300005],p[300005];
int find_root(int idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    int n,m,k,id = 1;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        p[i] = i;
    for(int i=1;i<=k;i++){
        scanf("%d %c %d",&a[i].l,&a[i].opr,&a[i].r);
        if(opr == '<'){
            in[a[i].r]++;
            g[a[i].l].push_back({a[i].r});
        }else{
            int ru = find_root(a[i].l);
            int rv = find_root(a[i].r);
            if(ru!=rv){
                p[ru] = rv;
            }
        }
    }
    return 0;
}
