/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,temp,minn;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> temp;
        if(temp == 0){
            cout << i-1;
            return 0;
        }
        if(i<k) continue;
        if(i == k){
            minn = temp;
            continue;
        }
        if(temp<minn){
            cout << i-1;
            return 0;
        }
    }
    cout << n;
	return 0;
}
