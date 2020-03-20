/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL fact[13];
LL n;
void print(LL num,LL bit1,LL bit0){
	cout << '1';
	bit1--;
	// if(bit0!=0)	n-=fact[num-1]/(fact[bit1]*fact[bit0-1]);
	for(LL i=2;i<=num;i++){
		if(bit1 == 0){
			cout << '0';
			bit0--;
		}else if(bit0 == 0){
			cout << '1';
			bit1--;
		}else if(fact[num-i]/(fact[bit1]*fact[bit0-1])>=n){
			cout << '0';
			bit0--;
		}else{
			cout << '1';
			n-=fact[num-i]/(fact[bit1]*fact[bit0-1]);
			bit1--;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL k,idx,sum = 0;
	fact[1] = fact[0] = 1;
	for(LL i=2;i<=11;i++)
		fact[i] = fact[i-1]*i;
	cin >> n >> k;
	for(LL i=0;i>=0;i++){
		LL temp = sum;
		sum+=(fact[k+i-1]/(fact[k-1]*fact[i]));
		// printf("%d %d: %d\n",k,i,sum);
		if(sum>=n){
			n-=temp;
			idx = i;
			break;
		}
	}
	print(k+idx,k,idx);
	return 0;
}