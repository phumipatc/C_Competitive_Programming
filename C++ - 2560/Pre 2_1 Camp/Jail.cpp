/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int  mark[1000100];
int main()
{
    int n,m,i,temp,ch=0,now;
    scanf("%d %d",&n,&m);
    now=m%n;
    while(ch<n-1){
        if(!mark[now]){
            if(now==0)  printf("%d ",n);
            else        printf("%d ",now);
            mark[now]=1;
            ch++;
        }
        temp=m;
        while(temp--){
            now++;
            now%=n;
            while(mark[now]){
                now++;
                now%=n;
            }
        }
    }
    printf("%d\n",now);
    return 0;
}
