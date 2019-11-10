/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[100100];
int main()
{
    int n,i,now;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&now);
        if(i>=3)
            mic[i]=max(mic[i-1],now+mic[i-3]);
    }
    printf("%d",mic[n]);
    return 0;
}
