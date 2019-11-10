/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list{
 char val[50];
 struct list *l;
 struct list *r;
};
typedef struct list list;
list *head = NULL,*cur;
list* createNode(char* x){
 list *node;
 node = (list*)malloc(sizeof(list));
 strcpy(node->val,x);
 node->l = NULL;
 node->r = NULL;
 return node;
}

void add(char* a){
  list* node = createNode(a);
  node -> r = cur->r;
  node -> l = cur;
  if(cur->r!=NULL)
    cur->r->l = node;
  cur->r=node;

}

void tail(){
  while(cur->r!=NULL){
    cur = cur->r;
  }
}

void del(){
  list *node;
  if(cur->r != NULL){
    node = cur->r;
    cur->r = node->r;
    if(cur->r != NULL)
        cur->r->l=cur;
    free(node);
  }
}

void next(){
    if(cur->r!=NULL)
        cur=cur->r;
}

void Head(){
        cur=head;
}

void call(){
    printf("%s\n",cur->val);
}

void List(){

  while(cur->r!=NULL){
    printf("%s ",cur->val);
    cur = cur->r;
  }
    printf("%s ",cur->val);
    printf("\n");
}

int main(){
 int n,i;
 char s[50],*word;
 head = createNode("999");
 cur = head;
 scanf("%d\n",&n);
 for(i=0;i<n;i++){
    gets(s);
    if(s[0]=='a'){
        word = &s[4];
        add(word);
    }else if(s[0]=='n')
        next();
    else if(s[0]=='h')
        Head();
    else if(s[0]=='t')
        tail();
    else if(s[0]=='r'){
        del();
    }
    else if(s[0]=='c')
        call();
    else if(s[0]=='l'){
        List();
    }

 }

return 0;
}
