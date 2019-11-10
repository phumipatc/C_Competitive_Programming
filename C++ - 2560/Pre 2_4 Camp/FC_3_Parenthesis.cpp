/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100100];
stack< char> st;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str);
        int len=strlen(str),ch=1;
        for(int i=0;i<len;i++){
            if(str[i]==')'){
                if(st.empty() || st.top()!='('){
                    ch=0;
                    break;
                }else
                    st.pop();
            }else if(str[i]=='}'){
                if(st.empty() || st.top()!='{'){
                    ch=0;
                    break;
                }else
                    st.pop();
            }else if(str[i]==']'){
                if(st.empty() || st.top()!='['){
                    ch=0;
                    break;
                }else
                    st.pop();
            }else
                st.push(str[i]);
        }
        if(ch && st.empty())    printf("yes\n");
        else                    printf("no\n");
        while(!st.empty())  st.pop();
    }
    return 0;
}
