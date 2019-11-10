/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool tree[5000010];
int countt = 0,k;
void update(int now){
    if(tree[now])   return ;
    tree[now] = true;
    int lvl = log2(now);
    if(lvl == k)    countt++;
    if(now!=1){
        if(tree[now/2]) update(now^1);
        if(tree[now^1]) update(now/2);
    }
    if(lvl!=k){
        if(tree[now*2])     update(now*2+1);
        if(tree[now*2+1])   update(now*2);
    }
}
int main(){
    int m,st,lv;
    scanf("%d %d",&k,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&lv,&st);
        update((st+(1<<k))>>lv);
        if(countt == 1<<k){
            printf("%d\n",i);
            break;
        }
    }
	return 0;
}