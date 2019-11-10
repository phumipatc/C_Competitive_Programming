/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[210];
stack<char> st;
int main(){
    int len;
    scanf(" %s",str);
    len = strlen(str);
    for(int i=0;i<len;i++){
        if(str[i] == ')' && !st.empty() && st.top() == '('){
            st.pop();
            continue;
        }
        st.push(str[i]);
    }
    printf("%d\n",st.size());
    return 0;
}
