/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    for(int i=1;i<=8;i++){
        scanf("%d",&a[i]);
        a[8+i]=a[i];
    }
    for(int i=1;i<=16;i++)
        a[i]+=a[i-1];
    int ans=-1;
    for(int i=4;i<=11;i++)
        ans=max(ans,a[i]-a[i-4]);
    printf("%d\n",ans);
    return 0;
}
