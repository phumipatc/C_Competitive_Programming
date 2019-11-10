/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],l[200100],r[200100];
int main()
{
    int i,n,k,mid;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==k) mid=i;
    }
    int sum=0;
    l[100000]++,r[100000]++;
    for(i=mid-1;i>0;i--){
        if(a[i]>a[mid]) sum++;
        else            sum--;
        l[100000+sum]++;
    }
    sum=0;
    for(i=mid+1;i<=n;i++){
        if(a[i]>a[mid]) sum++;
        else            sum--;
        r[100000+sum]++;
    }
    int ans=0;
    for(i=0;i<=200000;i++)
        ans+=l[i]*r[200000-i];
    cout << ans << endl;
    return 0;
}
