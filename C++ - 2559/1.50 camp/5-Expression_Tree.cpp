/*
    TASK:Expression Tree
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stack>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<stdlib.h>
using namespace std;
struct A{
    char a;
    struct A *l;
    struct A *r;
};
typedef struct A A;
stack<A *> st;
A *createnode(char a){
    A* node;
    node = (A *)malloc(sizeof(A));
    node -> a =a;
    node -> l = node->r = NULL;
    return node;
}
void pre(A *run){
    if(run==NULL)   return ;
    printf("%c",run->a);
    pre(run->l);
    pre(run->r);
}
void inf(A *run){
    if(run->l!=NULL){
        printf("(");    inf(run->l);
    }
    printf("%c",run->a);
    if(run->r!=NULL){
        inf(run->r);    printf(")");
    }
}
char b[500];
int main ()
{
    A *temp,*left,*right;
    int i,n,num,len;
    gets(b);
    len = strlen(b);
    for(i=0;i<len;i++){
        if(isalpha(b[i])){
            st.push(createnode(b[i]));
        }
        else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'){
            temp = createnode(b[i]);
            temp->r = st.top(); st.pop();
            temp->l = st.top(); st.pop();
            st.push(temp);
        }
    }
    temp=st.top();
    inf(temp);  printf("\n");
    pre(temp);  printf("\n");
    return 0;
}
