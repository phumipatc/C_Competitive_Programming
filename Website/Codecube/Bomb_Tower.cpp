/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
bool prime[500100];
int main()
{
    int n,b,i,j,countt=0;
    for(i=2;i<=500000;i++)  prime[i]=true;
    for(i=2;i<=sqrt(500000);i++)
        if(prime[i])
            for(j=i*i;j<=500000;j+=i)
                prime[j]=false;
    scanf("%d %d",&n,&b);
    for(i=2;i<=n;i++)
        if(prime[i])
            countt++;
    if(countt<=b)   printf("0\n");
    else            printf("%d\n",countt-b);
    return 0;
}
