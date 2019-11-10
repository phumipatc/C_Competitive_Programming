/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long double a,b,c,d;
int main(){
    scanf("%Le %Le %Le",&a,&b,&c);
    d=a+b;
    if(d==c)
        printf("Correct");
    if(d!=c)
        printf("Wrong");
return 0;
}
