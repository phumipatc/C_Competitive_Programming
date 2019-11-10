/*
    TASK:BST Travel 2
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num;
    struct A *l;
    struct A *r;
};
typedef struct A A;
A *root,*run;
A *createnode(int num){
    A *node;
    node=(A *)malloc(sizeof(A));
    node->l=NULL;
    node->r=NULL;
    node->num=num;
    return node;
}
void pre(A *run){
    if(run==NULL)
        return ;
    printf("%d ",run->num);
    pre(run->l);
    pre(run->r);
}
void pos(A *run){
    if(run==NULL)
        return ;
    pos(run->l);
    pos(run->r);
    printf("%d ",run->num);
}
void inf(A *run){
    if(run==NULL)
        return ;
    inf(run->l);
    printf("%d ",run->num);
    inf(run->r);
}
int main()
{
    int i,n,num;
    scanf("%d %d",&n,&num);
    root=createnode(num);
    run=createnode(num);
    for(i=1;i<n;i++){
        scanf("%d",&num);
        run=root;
        while(1){
            if(num>run->num && run->r==NULL){
                run->r=createnode(num);
                break;
            }
            if(num<run->num && run->l==NULL){
                run->l=createnode(num);
                break;
            }
            if(num>run->num)
                run=run->r;
            else if(num<run->num)
                run=run->l;
        }
    }
    pre(root);  printf("\n");
    pos(root);  printf("\n");
    inf(root);  printf("\n");
return 0;
}
