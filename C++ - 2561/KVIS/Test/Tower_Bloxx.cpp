/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10000019
using namespace std;
int fibo[110];
int main(){
    fibo[0] = fibo[1] = 1;
    for(int i=2;i<=100;i++)
        fibo[i] = (fibo[i-1]+fibo[i-2])%MOD;
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        printf("%d\n",fibo[n]);
    }
	return 0;
}
