/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n,m,k,l,countt,pass,idx,idx2,temp;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(k--){
        countt = 0,pass = 0;
        for(int i=0;i<m;i++){
            scanf("%d",&temp);
            idx = lower_bound(a+pass,a+n,temp-l)-a;
            // printf("%d ",idx);
            idx2 = upper_bound(a+pass,a+n,temp+l)-a-1;
            // printf("%d\n",idx2);
            countt+=max(0,idx2-idx+1);
            pass = idx2+1;
        }
        printf("%d\n",countt);
    }
	return 0;
}
