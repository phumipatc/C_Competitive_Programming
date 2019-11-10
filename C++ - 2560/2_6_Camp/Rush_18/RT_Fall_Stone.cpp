/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
A a[160005];
int p[160005],countt[160005];
int find_root(int idx){
    if(p[idx] == idx)   return idx;
    else                return p[idx] = find_root(p[idx]);
}
int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&a[i].i,&a[i].j);
    }
    return 0;
}
