/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[100100],countt[300100];
int main()
{
    int n,i,a,j,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        mic[i]=num;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            countt[mic[i]+mic[j]]++;
        }
    }
    scanf("%d",&a);
    printf("%d\n",countt[a]);
    return 0;
}
