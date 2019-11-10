/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int k[100010],n,m,i,mini=1<<30,high,low=0,mid,sum=0;
int main(){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&k[i]);
        if(mini>k[i])
            mini=k[i];
    }
    high=mini*m;
    while(low<high){
        mid=(low+high)/2;
        sum=0;
        for(i=0;i<n;i++)
            sum+=mid/k[i];
        if(sum>=m)
            high=mid;
        else
            low=mid+1;
    }
    printf("%d",high);
return 0;
}
