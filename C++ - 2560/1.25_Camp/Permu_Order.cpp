/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200],b[1200];
int main()
{
    int n,q,i,countt=0,mod;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    countt++;
    while(next_permutation(b,b+n)){
        countt++;
        for(i=0;i<n;i++){
            if(i==n-1 && a[i]==b[i]){
                goto next;
            }
            if(a[i]!=b[i])  break;
        }
    }
    next :
        while(q--){
            scanf("%d",&mod);
            printf("%d\n",countt%mod);
        }
	return 0;
}
/*

*/
