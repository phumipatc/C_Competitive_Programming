/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[45000];
int main(){
    int q,n,idx;
    scanf("%d",&q);
    for(int i=1;i<=44730;i++)
        a[i] = i*i;
    while(q--){
        scanf("%d",&n);
        idx = upper_bound(a+1,a+44725,n)-a;
        printf("%d\n",n-(idx-1));
    }
	return 0;
}
