/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[150100];
int main(){
    int n,l,r,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    l = 1,r = n;
    while(l<=r){
        ans+=a[l];
        if(l%3 == 0 && l!=r){
            ans+=a[r];
            r-=2;
        }
        l++;
    }
    printf("%d\n",ans);
    return 0;
}
