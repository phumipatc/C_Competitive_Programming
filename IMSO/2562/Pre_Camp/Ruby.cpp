/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[750010];
char opr[10];
void update(int idx,int v){
    while(idx<=750003){
        tree[idx]+=v;
        idx+=idx & -idx;
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
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s %d %d",opr+1,&u,&v);
        if(opr[1] == 'B')   update(v,u);
        else                printf("%d\n",query(v)-query(u-1));
    }
	return 0;
}