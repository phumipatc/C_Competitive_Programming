/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int orchid[1000100],LIS[1000100];
int main(){
    int idx,n,maxx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&orchid[i]);
    for(int i=0;i<n;i++){
        idx=upper_bound(LIS,LIS+maxx,orchid[i])-LIS;
        if(idx==maxx)   maxx++;
        LIS[idx]=orchid[i];
    }
    printf("%d\n",n-maxx);
    return 0;
}
