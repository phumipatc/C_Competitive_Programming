/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,q,st,en;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    cin >> q;
    while(q--){
        cin >> st >> en;
        cout << a[en]-a[st-1] << endl;
    }
	return 0;
}
