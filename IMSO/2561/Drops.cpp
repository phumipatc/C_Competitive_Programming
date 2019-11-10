/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main(){
    int h,l,n,countt = 0,ans = 0;
    scanf("%d %d %d",&h,&l,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[n+1] = 1e9;
    for(int i=1;i<=n;i++){
        if(a[i]<l || a[i]>l+h)  continue;
        countt++;
        if(a[i]!=a[i+1]){
            ans = max(ans,countt);
            countt = 0;
        }
    }
    printf("%d\n",ans);
    return 0;
}
