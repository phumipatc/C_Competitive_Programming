/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> b[100100],ans;
int a[100100];
int main()
{
    int n,i,num,m=0,idx,now,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num);
        idx=upper_bound(a,a+m,num)-a;
        if(idx>=1 && num==a[idx-1])
            continue;
        if(idx==m)
            m++;
        a[idx]=num;
        b[idx].push_back(num);
    }
    printf("%d\n",m);
    now=b[m-1][0];
    ans.push_back(now);
    for(i=m-2;i>=0;i--){
        for(j=0;j<b[i].size();j++){
            if(b[i][j]<now){
                now=b[i][j];
                ans.push_back(now);
                break;
            }
        }
    }
    for(i=m-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    return 0;
}
