/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> vect[100100];
int a[100100],LIS[100100],ans[100100];
int main()
{
    int n,index,i,m=0,now,k=0,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        index=upper_bound(LIS,LIS+m,a[i])-LIS;
        if(index>=1 && a[i]==LIS[index-1])  continue;
        if(m==index)    m++;
        LIS[index]=a[i];
        vect[index].push_back(a[i]);
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
