/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    int n = 8,maxx = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }
    for(int i=1;i<=2*n;i++)
        a[i]+=a[i-1];
    for(int i=4;i<=2*n;i++){
        maxx = max(maxx,a[i]-a[i-4]);
    }
    printf("%d",maxx);
	return 0;
}
