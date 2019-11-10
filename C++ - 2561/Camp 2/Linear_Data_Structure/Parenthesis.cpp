/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[130];
stack< char> st;
int main(){
    int q,ch,len;
    scanf("%d",&q);
    while(q--){
        ch = 0;
        scanf(" %s",str);
        len = strlen(str);
        for(int i=0;i<len;i++){
            if(str[i] == '(' || str[i] == '[')  st.push(str[i]);
            if(str[i] == ')'){
                if(!st.empty() && st.top() == '(')  st.pop();
                else{
                    ch = 1;
                    break;
                }
            }else if(str[i] == ']'){
                if(!st.empty() && st.top() == '[')  st.pop();
                else{
                    ch = 1;
                    break;
                }
            }
        }
        if(ch || !st.empty())   printf("No\n");
        else                    printf("Yes\n");
        while(!st.empty())  st.pop();
    }
	return 0;
}
