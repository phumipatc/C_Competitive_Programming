/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100],b[1100];
int main(){
    int n,k,sum;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        b[i] = 1e9;
    for(int i=1;i<=n;i++){
        sum = a[i];
        b[1] = min(b[1],sum);
        for(int j=i+1;j<=n;j++){
            sum += a[j];
            b[j-i+1] = min(b[j-i+1],sum);
        }
    }
    int num,idx;
    while(k--){
        scanf("%d",&num);
        idx = upper_bound(b+1,b+n+1,num)-(b+1);
        printf("%d\n",idx);
    }
    return 0;
}
