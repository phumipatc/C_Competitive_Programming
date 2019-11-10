/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int LIS[1000100];
int main(){
    int n,idx,maxx=0,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        idx=upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx==maxx)   maxx++;
        LIS[idx]=num;
    }
    printf("%d\n",n-maxx);
    return 0;
}
