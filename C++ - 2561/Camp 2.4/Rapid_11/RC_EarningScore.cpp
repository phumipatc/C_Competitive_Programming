/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define v first
#define id second
using namespace std;
pair<int ,int > a[55];
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].v,&a[i].id);
    }
	return 0;
}