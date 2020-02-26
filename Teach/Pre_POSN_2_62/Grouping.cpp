/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10100];
int main(){
    int n,m,l,r,mid,countt,sum,maxx=-1e9;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),maxx = max(maxx,a[i]);
    l = 0,r = 2e9;
    while(l<r){
        mid = (l+r+1)/2,sum = 0,countt = 1;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum>mid) countt++,sum = a[i];
        }
        if(countt<m)    r = mid-1;
        else            l = mid;
    }
    if(l<maxx)	printf("IMPOSSIBLE\n");
    else		printf("%d\n",l);
    return 0;
}
