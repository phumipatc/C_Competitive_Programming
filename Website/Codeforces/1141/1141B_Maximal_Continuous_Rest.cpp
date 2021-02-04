/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[400010];
int main(){
    int n,countt = 0,maxx = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i+n] = a[i];
    }
    for(int i=1;i<=2*n;i++){
        if(a[i] == 0){
            countt = 0;
        }else{
            countt++;
            maxx = max(maxx,countt);
        }
    }
    cout << maxx << endl;
	return 0;
}
