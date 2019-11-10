/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[1<<21];
void pre(int now){
    if(tree[now] == -1) return ;
    printf("%d\n",tree[now]);
    pre(now*2);
    pre((now*2)+1);
}
void pos(int now){
    if(tree[now] == -1) return ;
    pos(now*2);
    pos((now*2)+1);
    printf("%d\n",tree[now]);
}
void inf(int now){
    if(tree[now] == -1) return ;
    inf(now*2);
    printf("%d\n",tree[now]);
    inf((now*2)+1);
}
void bfs(){
    for(int i=1;i<=1<<20;i++)
        if(tree[i] != -1)
            printf("%d\n",tree[i]);
}
char opr[5];
int main(){
    int n,num,now;
    scanf(" %s %d",opr,&n);
    memset(tree,-1,sizeof tree);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        now = 1;
        while(tree[now]!=-1){
            if(num<tree[now])   now = now*2;
            else                now = (now*2)+1;
        }
        tree[now] = num;
    }
    if(!strcmp(opr,"PRE"))      pre(1);
    else if(!strcmp(opr,"POS")) pos(1);
    else if(!strcmp(opr,"INF")) inf(1);
    else if(!strcmp(opr,"BFS")) bfs();
	return 0;
}
