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
A tree[100010];
int main(){
    int n,num,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        tree[i] = {(int)1e9,(int)1e9,(int)1e9};
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        now = 1;
        while(tree[now].v!=1e9){
            if(num<tree[now].v){
                printf("L");
                if(tree[now].l == 1e9){
                    tree[now].l = i;
                    break;
                }
                now = tree[now].l;
            }else{
                printf("R");
                if(tree[now].r == 1e9){
                    tree[now].r = i;
                    break;
                }
                now = tree[now].r;
            }
        }
        tree[i].v = num;
        printf("*\n");
    }
	return 0;
}
