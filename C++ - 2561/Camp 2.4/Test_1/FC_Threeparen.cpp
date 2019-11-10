/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack<char > st;
char a[100010];
int main(){
    int q,len,ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a+1);
        len = strlen(a+1),ch = 1;
        for(int i=1;i<=len;i++){
            if(a[i] == '(' || a[i] == '[' || a[i] == '{')   st.push(a[i]);
            else if(a[i] == ')'){
                if(st.empty() || st.top()!='('){
                    ch = 0;
                    break;
                }
                st.pop();
            }else if(a[i] == ']'){
                if(st.empty() || st.top()!='['){
                    ch = 0;
                    break;
                }
                st.pop();
            }else if(a[i] == '}'){
                if(st.empty() || st.top()!='{'){
                    ch = 0;
                    break;
                }
                st.pop();
            }
        }
        if(ch && st.empty())    printf("yes\n");
        else                    printf("no\n");
        while(!st.empty())  st.pop();
    }
	return 0;
}
