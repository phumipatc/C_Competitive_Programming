/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char b;
    A *l,*r;
};
A* createnode(char c){
    A* node;
    node=(A *)malloc(sizeof(A));
    node->b=c;
    node->l=node->r=NULL;
    return node;
}
char str[500];
stack< A*> st;
void inf(A* run){
    if(run==NULL)   return ;
    if(run->l!=NULL)
        printf("(");
    inf(run->l);
    printf("%c",run->b);
    inf(run->r);
    if(run->r!=NULL)
        printf(")");
}
void pre(A* run){
    if(run==NULL)   return ;
    printf("%c",run->b);
    pre(run->l);
    pre(run->r);
}
int main(){
    int len,i;
    A *temp1,*temp2,*temp3;
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]==' ') continue;
        if(isalpha(str[i]))
            st.push(createnode(str[i]));
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            temp2=st.top();
            st.pop();
            temp1=st.top();
            st.pop();
            temp3=createnode(str[i]);
            temp3->l=temp1;
            temp3->r=temp2;
            st.push(temp3);
        }
    }
    temp3=st.top();
    inf(temp3);      printf("\n");
    pre(temp3);     printf("\n");
    return 0;
}
