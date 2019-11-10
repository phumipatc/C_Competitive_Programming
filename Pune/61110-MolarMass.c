/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack<int> st;
char str[110];
int main(){
    int q,sum,len;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str);
        len = strlen(str);
        for(int i=0;i<len;i++){
            if(str[i] == '('){
                st.push(-1);
            }else if(str[i] == ')'){
                sum = 0;
                while(!st.empty() && st.top() != -1){
                    sum+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(sum);
            }else if(isalpha(str[i])){
                if(str[i] == 'H')
                    st.push(1);
                else if(str[i] == 'C')
                    st.push(12);
                else
                    st.push(16);
            }else{
                sum = st.top();
                st.pop();
                st.push(sum*(str[i]-'0'));
            }
        }
        sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        printf("%d",sum);
    }
    return 0;
}
