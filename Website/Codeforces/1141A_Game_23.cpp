/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,now,countt = 0;
    cin >> n >> m;
    if(m%n){
        cout << "-1" << endl;
        return 0;
    }
    m/=n;
    while(m%2 == 0) countt++,m/=2;
    while(m%3 == 0) countt++,m/=3;
    if(m == 1)  cout << countt << endl;
    else        cout << "-1" << endl;
	return 0;
}
