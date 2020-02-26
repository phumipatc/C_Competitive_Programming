/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > v;
vector<int > ::iterator it;
int main(){
	v.push_back(4);
	v.insert(it,3);
	v.pop_back();
	return 0;
}