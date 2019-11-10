/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],l[200005],r[200005];
int main(){
    int n,k,mid,sum,ans;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i] == k)   mid = i;
    }
    sum = 0;
    l[100000] = r[100000] = 1;
    for(int i=mid-1;i>0;i--){
        if(a[i]>a[mid]) sum++;
        else            sum--;
        l[100000+sum]++;
    }
    sum=0;
    for(int i=mid+1;i<=n;i++){
        if(a[i]>a[mid]) sum++;
        else            sum--;
        r[100000+sum]++;
    }
    ans = 0;
    for(int i=0;i<=200000;i++)
        ans+=(l[i]*r[200000-i]);
    printf("%d\n",ans);
    return 0;
}
