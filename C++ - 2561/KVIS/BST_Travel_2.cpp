/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,l,r;
};
A tree[310];
void pre(int now){
    if(tree[now].v == 0)    return ;
    printf("%d ",tree[now].v);
    pre(tree[now].l);
    pre(tree[now].r);
}
void pos(int now){
    if(tree[now].v == 0)    return ;
    pos(tree[now].l);
    pos(tree[now].r);
    printf("%d ",tree[now].v);
}
void inf(int now){
    if(tree[now].v == 0)    return ;
    inf(tree[now].l);
    printf("%d ",tree[now].v);
    inf(tree[now].r);
}
int main(){
    int n,num,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        now = 1;
        while(tree[now].v){
            if(num<tree[now].v){
                if(!tree[now].l){
                    tree[now].l = i;
                    break;
                }
                now = tree[now].l;
            }else{
                if(!tree[now].r){
                    tree[now].r = i;
                    break;
                }
                now = tree[now].r;
            }
        }
        tree[i].v = num;
    }
    pre(1);
    printf("\n");
    pos(1);
    printf("\n");
    inf(1);
    printf("\n");
	return 0;
}
