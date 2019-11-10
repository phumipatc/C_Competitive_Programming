/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,countt = 1,maxx = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        if(a[i]<a[i-1]) countt = 1;
        else            countt++;
        maxx = max(maxx,countt);
    }
    printf("%d\n",maxx);
	return 0;
}