/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[210];
int main(){
    int q,n,countt;
    scanf("%d",&q);
    while(q--){
        countt = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        while(a[0]!=0){
            countt++;
            for(int i=1;i<n;i++)    a[i]--;
            sort(a,a+n);
        }
        printf("%d\n",countt);
    }
    return 0;
}
