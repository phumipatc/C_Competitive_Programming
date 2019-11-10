/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100],countt[100100];
int main()
{
    long long n,k,idx,ans=0;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a[i];
        countt[a[i]]++;
    }
    cin >> k;
    for(long long i=0;i<=k;i++)
        if(i!=k-i)
            ans+=countt[i]*countt[k-i];
        else
            ans+=countt[i]*(countt[i]-1);
    cout << ans/2;
    return 0;
}
/*
5
1 3 4 3 0
4
*/
