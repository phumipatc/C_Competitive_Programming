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
list* createnode(char* x){
    list *node;
    node=(list*)malloc(sizeof(list));
    strcpy(node->val,x);
    node->l=NULL;
    node->r=NULL;
    return node;
}
void insert(char* x){
    list* node=createnode(x);
    node->r=cur->r;
    node->l=cur;
    if(cur->r!=NULL)
        cur->r->l=node;
    cur->r=node;
    cur=cur->r;
}
void back(){
    list *p=cur->l;
    list *node=cur;
    if(cur->l!=NULL){
        if(cur->r==NULL)
            p->r=NULL;
        else{
            p->r=p->r->r;
            p->r->l=p;
        }
        cur=p;
        free(node);
    }
}
void del(){
    list *node;
    if(cur->r!=NULL){
        node=cur->r;
        cur->r=node->r;
        if(cur->r!=NULL)
            cur->r->l=cur;
        free(node);
    }
}
void left(){
    if(cur->l!=NULL)
        cur=cur->l;
}
void right(){
    if(cur->r!=NULL)
        cur=cur->r;
}
void printlist(){
    cur=head->r;
    while(cur!=NULL){
        printf("%s",cur->val);
        cur=cur->r;
    }
}
int main(){
    int n,i;
    char s[50],*word;
    head=createnode("xxx");
    cur=head;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        gets(s);
        if(s[0]=='i'){
            word=&s[2];
            insert(word);
        }else if(s[0]=='l')
            left();
        else if(s[0]=='r')
            right();
        else if(s[0]=='b')
            back();
        else if(s[0]=='d')
            del();
    }
    printlist();
return 0;
}
