/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> vect[100100];
int num[100100],LIS[100100],ans[100100];
int main()
{
    int n,i,idx,m=0,now,j,k=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n;i++){
        idx=upper_bound(LIS,LIS+m,num[i])-LIS;
        if(idx>=1 && LIS[idx-1]==num[i])  continue;
        if(idx==m)  m++;
        LIS[idx]=num[i];
        vect[idx].push_back(num[i]);
    }
    printf("%d\n",m);
    now=vect[m-1][0];
    ans[k++]=now;
    for(i=m-2;i>=0;i--){
        for(j=0;j<vect[i].size();j++){
            if(vect[i][j]<now){
                now=vect[i][j];
                ans[k++]=now;
                break;
            }
        }
    }
    for(i=k-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    return 0;
}
/*
8
-7 10 9 2 3 8 8 1

10
6 3 4 8 10 5 7 1 9 2
*/
