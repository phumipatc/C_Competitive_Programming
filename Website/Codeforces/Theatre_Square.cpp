/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,k;
    cin >> n >> m >> k;
    cout << (long long )ceil((double )n/k)*(long long )ceil((double )m/k);
	return 0;
}
