/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    int n,sum=0,summ=0,maxx=-1e8;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i%2==0)  a[i]*=(-1);
        sum+=a[i];
    }
    for(int i=0;i<n;i++){
        summ+=a[i];
        if(summ<0)  summ=0;
        maxx=max(maxx,summ);
    }
    printf("%d\n",sum-(maxx*2));
    return 0;
}
