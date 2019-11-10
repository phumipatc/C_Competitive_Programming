/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,countt=0;
char a[30],ans[100000][30];
void parenthesis(int open,int close){
    int now=open+close;
    if(open<n || close<n){
        if(open<n){
            a[now]='(';
            parenthesis(open+1,close);
        }
        if(close<n && close<open){
            a[now]=')';
            parenthesis(open,close+1);
        }
    }else{
        strcpy(ans[countt++],a);
    }
}
int main()
{
    int i;
    scanf("%d",&n);
    parenthesis(0,0);
    printf("%d\n",countt);
    for(i=0;i<countt;i++)
        printf("%s\n",ans[i]);
	return 0;
}
