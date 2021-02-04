/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a!=d || (a == 0 && c>0)) printf("0\n");
    else                        printf("1\n");
	return 0;
}
