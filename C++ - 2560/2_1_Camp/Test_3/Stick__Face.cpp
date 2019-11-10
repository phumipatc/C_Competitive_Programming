/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int check[200100],countt[200100];
int main(){
    int n,a,i,k,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        check[i] = 1;
    for(i=1;i<=k;i++){
        scanf("%d",&a);
        check[a] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            if(check[i] == 0 || check[j] == 0)    continue;
            countt[j-i]++;
        }
    }
    for(i=1;i<=n-1;i++)
        printf("%d\n",countt[i]);
    return 0;
}
