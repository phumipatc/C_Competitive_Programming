/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],countt[1000100],ans[1000100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        countt[a[i]]++;
    }
    for(int i=1;i<=1000000;i++){
        if(!countt[i])  continue;
        for(int j=i;j<=1000000;j+=i)
            ans[j]+=countt[i];
    }
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[a[i]]-1);
	return 0;
}
