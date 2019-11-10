/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[55],mic[55][55];
int mem(int fron,int len,int st,int en){
    if(mic[st][en]) return mic[st][en];
    if(st==en)      return 0;
    int i,mi=1e9;
    for(i=st;i<en;i++)
        mi=min(mi,mem(fron,a[i]-fron,st,i)+mem(a[i],len-a[i]+fron,i+1,en)+len);
    return mic[st][en]=mi;
}
int main()
{
    int p,n,i;
    scanf("%d %d",&n,&p);
    for(i=0;i<p;i++)
        scanf("%d",&a[i]);
    printf("%d",mem(0,n,0,p));
    return 0;
}
