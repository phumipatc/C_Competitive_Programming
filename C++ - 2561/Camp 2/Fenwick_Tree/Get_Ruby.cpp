/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[750100],n;
void update(int idx,int v){
    while(idx<=n){
        tree[idx]+=v;
        idx+=(idx & -idx);
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
char opr[7];
int main(){
    int m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s %d %d",opr,&a,&b);
        if(opr[0] == 'B'){
            update(b,a);
        }else{
            printf("%d\n",query(b)-query(a-1));
        }
    }
	return 0;
}
