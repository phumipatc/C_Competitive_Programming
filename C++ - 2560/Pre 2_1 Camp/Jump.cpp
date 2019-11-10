/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int num[30100];
int main()
{
    int n,k,i,ans=-1,idx;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n;i++){
        idx=upper_bound(num,num+n,num[i]+k)-num;
        idx--;
        ans=max(ans,idx-i);
    }
    printf("%d\n",ans);
    return 0;
}
/*
11 6
3 6 7 9 10 11 13 16 18 19 20

3 30000
2000 35000 55000
*/
