/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[500010];
void update(int idx,int v){
    while(idx<=500005){
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
string opr;
int main(){
    int n,m,a,b,c;
    scanf("%d %d",&n,&m);
    while(m--){
        cin >> opr;
        if(opr == "Yoyo"){
            scanf("%d %d %d",&c,&a,&b);
            if(a>b) swap(a,b);
            update(a,c);
            update(b+1,-c);
        }else{
            scanf("%d",&c);
            printf("%d\n",query(c));
        }
    }
	return 0;
}
