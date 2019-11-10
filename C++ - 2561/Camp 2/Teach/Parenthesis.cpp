/*
    TASK: Parenthesis
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
stack <char> st;
char str[200];
int main()
{
	int q,len,i,ch;
	scanf("%d",&q);
	while(q--){
        scanf(" %s",str);
        len = strlen(str),ch=1;
        for(i=0;i<len;i++){
            if(str[i]=='('||str[i]=='[')    st.push(str[i]);
            else if(!st.empty()&&str[i]==')'&&st.top()=='(')    st.pop();
            else if(!st.empty()&&str[i]==']'&&st.top()=='[')    st.pop();
            else    ch=0;
        }
        printf((ch&&st.empty())?"Yes\n":"No\n");
        while(!st.empty())
            st.pop();
	}
    return 0;
}
/*
3 ([]) (([()]))) ([()[]()])()
*/
