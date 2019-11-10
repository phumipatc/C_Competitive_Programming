/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100];
int main(){
    int n,k,p;
    scanf("%d %d %d",&n,&k,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),b[i] = a[i];
    sort(b+1,b+n+1);
    int l = 1,r = n;
    while(l<r){
        int mid = (l+r)/2,countt = 0;
        for(int i=1;i<=n;){
            if(a[i]>b[mid])
                countt++,i+=p;
            else
                i++;
        }
        if(countt>k)    l = mid+1;
        else            r = mid;
    }
    printf("%d\n",b[l]);
    return 0;
}
