/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1010][1010],a[1010],n;
int memo(int now,int last){
    if(now<1 || now>n)      return 1e9;
    if(mic[now][last]!=-1)  return mic[now][last];
    if(now==n)              return a[n];
    return mic[now][last]=a[now]+min(memo(now-last,last),memo(now+last+1,last+1));

}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(mic,-1,sizeof mic);
    printf("%d\n",memo(2,1));
    return 0;
}
