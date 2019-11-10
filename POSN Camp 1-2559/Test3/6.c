/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list{
    char val[50];
    struct list *l;
    struct list *r;
};
typedef struct list list;
list *head=NULL,*cur;
list* createnode(int* x){
    list *node;
    node=(list*)malloc(sizeof(list));
    strcpy(node->val,x);
    node->l=NULL;
    node->r=NULL;
    return node;
}
void back(int* a,int* b){
    list* node=createnode();
    node->r=cur->r;
    node->l=cur;
    if(cur->r!=NULL)
        cur->r->l=node;
    cur->r=node;
    cur=cur->r;
}
void front(int a,int b){

}
int main()
{
    int n,k,a,b,c,i;
    scanf("%d %d",&n,&k);
    head=createnode(1);
    cur=head;
    for(i=0;i<k;i++){
        scanf("%c %d %d",&a,&b,&c);
        if(a=='A'){
            front(b,c);
        }else if(a=='B'){
            back(b,c);
        }
    }
return 0;
}
