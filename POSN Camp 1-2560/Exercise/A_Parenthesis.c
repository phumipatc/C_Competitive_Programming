/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack< char> A;
char a;
int main(){
    int len;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='('){
            A.push(a[i]);
        }else if(isdigit(a[i])==0){
            A.push(a[i]);
        }else if(a[i]==')'){
            while(A.top!='('){
                    sum+=A.top()-'0';
                    A.pop();
            }
        }
    }
    return 0;
}
