/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    cin >> n;
    while(n>=10)    ans+=3000,n-=min(n,15);
    while(n>=4)     ans+=1500,n-=min(n,5);
    while(n>=2)     ans+=800,n-=min(n,2);
    while(n)        ans+=500,n--;
    cout << ans << endl;
	return 0;
}