/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300005],qs[300005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        qs[i] = a[i]+qs[i-1];
    }

    return 0;
}
