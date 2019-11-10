/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,m,st,k,idx,idx2;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(m--){
        scanf("%d %d",&st,&k);
        st--;
        idx = st,idx2 = st+k-1;
        while(idx<idx2){
            swap(a[idx%n],a[idx2%n]);
            idx++,idx2--;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
	return 0;
}
