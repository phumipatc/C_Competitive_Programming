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
    int n,k,idx,num;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i>0) a[i]+=a[i-1];
    }
    while(k--){
        cin >> num;
        idx = upper_bound(a,a+n,num)-a;
        printf("%d\n",idx);
    }
	return 0;
}
