/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
int main()
{
    int q,k,i,len,ans,countt;
    scanf("%d %d",&q,&k);
    while(q--){
        ans=0;
        scanf(" %s",a);
        len=strlen(a);
        if(((a[len-1]-'0')%2==0 && k%2==0) || ((a[len-1]-'0')%2==1 && k%2==1))
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
