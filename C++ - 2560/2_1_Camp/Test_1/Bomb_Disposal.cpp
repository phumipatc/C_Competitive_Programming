/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long s,m;
    cin >> s >> m;
    long long l=0,r=s/2;
    while(l<=r){
        long long mid=(l+r)/2;
        long long b=s-mid;
        if(mid*b>m || mid*b/b!=mid)    r=mid-1;
        else if(mid*b<m)               l=mid+1;
        else{
            cout << mid << " " << b;
            return 0;
        }
    }
    printf("Goodbye T-T\n");
    return 0;
}
