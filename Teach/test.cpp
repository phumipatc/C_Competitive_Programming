/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c;
int mod_of_pow(int a,int b){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	int div = mod_of_pow(a,b/2)%c;
	if(b%2)	return (((div*div)%c)*a)%c;
	else	return (div*div)%c;
}
int main(){
	int q,a,b;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",mod_of_pow(a,b));
	}
	return 0;
}