/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
void a(int i){
    if(i>m)
        return;
    printf("sin(%d",i);
    if(i<m){
        if(i%2==1)
            printf("-");
        else
            printf("+");
    }
    a(i+1);
    printf(")");
}
void s(int i){
    if(i>n)
        return;
    m=i;
    a(1);
    if(i<n)
        printf("+%d)",n-i+1);
    s(i+1);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)
        printf("(");
    s(1);
    printf("+1\n");
return 0;
}
