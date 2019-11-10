/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[10];
int tree[1<<21];
void pre(int i){
    if(tree[i]==-1)
        return ;
    printf("%d\n",tree[i]);
    pre(2*i);
    pre((2*i)+1);
}
void pos(int i){
    if(tree[i]==-1)
        return ;
    pos(2*i);
    pos((2*i)+1);
    printf("%d\n",tree[i]);
}
void inf(int i){
    if(tree[i]==-1)
        return ;
    inf(2*i);
    printf("%d\n",tree[i]);
    inf((2*i)+1);
}
void bfs(int i){
    for(i=1;i<1<<21;i++){
        if(tree[i]!=-1)
            printf("%d\n",tree[i]);
    }
}
int main()
{
    memset(tree,-1,sizeof tree);
    int n,i,num,r;
    scanf(" %s",a);
    scanf("%d %d",&n,&num);
    tree[1]=num;
    for(i=1;i<n;i++){
        scanf("%d",&num);
        for(r=1;tree[r]!=-1;){
            if(num>tree[r])
                r=2*r+1;
            else if(num<tree[r])
                r=2*r;
        }
        tree[r]=num;
    }
    if(!strcmp(a,"PRE"))
        pre(1);
    if(!strcmp(a,"POS"))
        pos(1);
    if(!strcmp(a,"INF"))
        inf(1);
    if(!strcmp(a,"BFS"))
        bfs(1);
return 0;
}
