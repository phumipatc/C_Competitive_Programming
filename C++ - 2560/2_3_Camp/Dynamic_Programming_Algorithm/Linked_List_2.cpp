/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int LIS[500100];
int main(){
    int n,maxx=0,num,idx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        idx=upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx==maxx)
            maxx++;
        LIS[idx]=num;
    }
    printf("%d\n",n-maxx);
    return 0;
}
