/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[30],b[30];
int main()
{
    int i,temp,n,j,ans=0;
    a[0]=1;
    for(i=1;i<=20;i++)
        a[i]=a[i-1]*3;
    scanf("%d",&n);
    i=0;
    while(n)
        b[i++]=n%3,n/=3;
    for(i=0;i<=20;i++){
        if(b[i]==2)
            b[i]=-1,b[i+1]++;
        else if(b[i]==3)
            b[i+1]++,b[i]=0;
    }
    for(i=0,j=0,ans=0;i<=20;i++){
        if(b[i]==1 || b[i]==-1)
            j++;
        if(b[i]!=-1)
            ans+=a[i]*b[i];
    }
    printf("%d %d",j,ans);
    return 0;
}
