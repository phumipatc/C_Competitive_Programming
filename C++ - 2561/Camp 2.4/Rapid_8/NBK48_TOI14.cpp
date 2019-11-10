/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[100010];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(int i=n-1;i>=1;i--)
        qs[i] = min(qs[i],qs[i+1]);
    int num,idx;
    while(q--){
        scanf("%d",&num);
        idx = upper_bound(qs+1,qs+n+1,num)-qs-1;
        printf("%d\n",idx);
    }
	return 0;
}