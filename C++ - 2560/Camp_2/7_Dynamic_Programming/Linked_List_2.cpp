/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main()
{
    int n,i,num,m=0,idx,now,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        idx=upper_bound(a,a+m,num)-a;
        if(idx==m)
            m++;
        a[idx]=num;
    }
    printf("%d",n-m);
    return 0;
}
