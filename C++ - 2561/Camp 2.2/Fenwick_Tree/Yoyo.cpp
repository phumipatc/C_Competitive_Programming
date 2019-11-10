/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[500010];
char opr[5];
void update(int idx,int v){
    while(idx<=500003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s",opr);
        if(opr[0] == 'Y'){
            scanf("%d %d %d",&a,&b,&c);
            if(b>c) swap(b,c);
            update(b,a);
            update(c+1,-a);
        }else{
            scanf("%d",&a);
            printf("%d\n",query(a));
        }
    }
	return 0;
}
