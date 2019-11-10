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
    cin >> n >> q;
    while(q--){
        cin >> st >> en;
        a[st]++;
        a[en+1]--;
    }
    cin >> q;
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    while(q--){
        cin >> st;
        cout << a[st] << endl;
    }
	return 0;
}
