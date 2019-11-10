/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[100010];
int main(){
    int n,q,k,idx;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&qs[i]);
        if(i == 0)  continue;
        qs[i]+=qs[i-1];
    }
    for(int i=n-2;i>=0;i--)
        qs[i] = min(qs[i],qs[i+1]);
    while(q--){
        scanf("%d",&k);
        idx = upper_bound(qs,qs+n,k)-qs;
        printf("%d\n",idx);
    }
	return 0;
}
