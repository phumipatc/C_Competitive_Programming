/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
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
list *head=NULL,*cur,*oldcur;
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
}
void deleted(){
    list *node;
    if(cur->r!=NULL){
        node=cur->r;
        cur->r=node->r;
        if(cur->r!=NULL)
            cur->r->l=cur;
        free(node);
    }
}
void printlist(){
    while(cur->r!=NULL){
        printf("%s ",cur->val);
        cur=cur->r;
    }
    printf("%s",cur->val);
}
int main()
{
    int n,i;
    char *word,command[10],s[10];
    head=createnode("999");
    cur=head;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf(" %s",command);
        if(command[0]=='h'){
            cur=head;
        }
        if(command[0]=='n'){
            cur=cur->r;
        }
        if(command[0]=='t'){
            while(cur->r!=NULL){
                cur=cur->r;
            }
        }
        if(command[0]=='a'){
            scanf(" %s",s);
            word=&s[0];
            insert(word);
        }
        if(command[0]=='r'){
            deleted();
        }
        if(command[0]=='c'){
            printf("%s\n",cur->val);
        }
        if(command[0]=='l'){
            printlist();
            printf("\n");
        }
    }
    return 0;
}
/*
9
i peat
i pot
l
i perfect
r
b
d
l
d
*/
