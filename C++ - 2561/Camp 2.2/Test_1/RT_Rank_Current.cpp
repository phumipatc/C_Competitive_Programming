/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int opr,num;
};
A a[300010];
int b[300010],tree[300010];
void update(int idx,int v){
    while(idx<=300003){
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
    int n,idx = 1,pos;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].opr,&a[i].num);
        if(a[i].opr == 1)   b[idx++] = a[i].num;
    }
    sort(b+1,b+idx);
    for(int i=1;i<=n;i++){
        if(a[i].opr == 1){
            pos = lower_bound(b+1,b+idx,a[i].num)-b;
            // printf("update : %d\n",pos);
            update(pos,1);
        }else{
            pos = lower_bound(b+1,b+idx,a[i].num)-b;
            printf("%d\n",query(pos-1)+1);
        }
    }
	return 0;
}
