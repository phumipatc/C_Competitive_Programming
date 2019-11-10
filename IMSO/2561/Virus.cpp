/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],c[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]),b[i]*=-1;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        c[i] = min(a[i],-b[i]);
    int l = 1,r = 1000000100,mid,ch;
    while(l<r){
        mid = (l+r)/2,ch = 1;
        for(int i=1;i<=n;i++){
            if(mid<c[i]){
                ch = 0;
                break;
            }
        }
        if(ch)  r = mid;
        else    l = mid+1;
    }
    printf("%d\n",l);
    return 0;
}
