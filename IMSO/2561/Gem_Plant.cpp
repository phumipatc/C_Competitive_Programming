/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[200100];
void update(int idx,int v){
    while(idx<=200010){
        tree[idx]+=v;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    int n,m,opr,l,r;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&opr,&l,&r);
        if(opr == 1){
            update(r,l);
        }else{
            printf("%d\n",query(r)-query(l-1));
        }
    }
    return 0;
}
