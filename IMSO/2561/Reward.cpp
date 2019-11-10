/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[500100];
int main(){
    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int l = 1,r = 1e9;
    while(l<r){
        int mid = (l+r)/2,sum = 0;
        for(int i=1;i<=n;i++)
            sum+=ceil((double)a[i]/mid);
        if(sum<=b)  r = mid;
        else        l = mid+1;
    }
    printf("%d\n",l);
    return 0;
}
