/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL a,b,c,sum;
	cin >> a >> b >> c;
	sum = a+b+c;
	if(sum>=80)			cout << "A\n";
	else if(sum>=75)	cout << "B+\n";
	else if(sum>=70)	cout << "B\n";
	else if(sum>=65)	cout << "C+\n";
	else if(sum>=60)	cout << "C\n";
	else if(sum>=55)	cout << "D+\n";
	else if(sum>=50)	cout << "D\n";
	else				cout << "F\n";
	return 0;
}