/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct A{
    char v[50];
    struct A *l;
    struct A *r;
};
typedef struct A A;
A *head = NULL,*cur;
char str[50],*word;
A* createnode(char* a){
    A *node;
    node = (A*)malloc(sizeof(A));
    strcpy(node->v,a);
    node->l = NULL;
    node->r = NULL;
    return node;
}
void insert(char* a){
    A* node = createnode(a);
    node->r = cur->r;
    node->l = cur;
    if(cur->r != NULL)
        cur->r->l = node;
    cur->r = node;
    cur = cur->r;
}
void back(){
    A *p = cur->l,*node = cur;
    if(cur->l != NULL){
        if(cur->r == NULL)
            p->r = NULL;
        else{
            p->r = p->r->r;
            p->r->l = p;
        }
        cur = p;
        free(node);
    }
}
void del(){
    A *node;
    if(cur->r != NULL){
        node = cur->r;
        cur->r = node->r;
        if(cur->r != NULL)
            cur->r->l = cur;
        free(node);
    }
}
void leftt(){
    if(cur->l != NULL)
        cur = cur->l;
}
void rightt(){
    if(cur->r != NULL)
        cur = cur->r;
}
void printlist(){
    cur = head->r;
    while(cur->r != NULL)
        printf("%s",cur->v);
}
int main(){
    int n,i;
    head = createnode("xxx");
    cur = head;
    scanf(" %d",&n);
    while(n--){
        gets(str);
        switch(str[0]){
            case 'i' : insert(&str[2]); break;
            case 'l' : leftt();         break;
            case 'r' : rightt();        break;
            case 'b' : back();          break;
            case 'd' : del();           break;
        }
    }
    printlist();
	return 0;
}
