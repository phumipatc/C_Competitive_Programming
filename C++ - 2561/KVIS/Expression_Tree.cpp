/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char v;
    int num,l,r;
};
A now,l,r,a[260];
stack< A> st;
void in(int now){
    if(now == 0)    return ;
    if(a[now].l == a[now].r){
        printf("%c",a[now].v);
        return ;
    }
    printf("(");
    in(a[now].l);
    printf("%c",a[now].v);
    in(a[now].r);
    printf(")");
}
void pre(int now){
    if(now == 0)    return ;
    printf("%c",a[now].v);
    pre(a[now].l);
    pre(a[now].r);
}
char str[260];
int main(){
    int len;
    gets(str+1);
    len = strlen(str+1);
    for(int i=1;i<=len;i++){
        if(str[i] == ' ')   continue;
        if(isalpha(str[i])){
            a[i].v = str[i];
            a[i].num = i;
            st.push(a[i]);
        }else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            r = st.top();
            st.pop();
            l = st.top();
            st.pop();
            a[i].v = str[i];
            a[i].l = l.num;
            a[i].r = r.num;
            a[i].num = i;
            st.push(a[i]);

        }
    }
    in(st.top().num);
    printf("\n");
    pre(st.top().num);
	return 0;
}
