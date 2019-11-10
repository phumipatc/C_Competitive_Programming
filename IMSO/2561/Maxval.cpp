/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int n,k,ans = -1e9,sum = 0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(i>=k){
            sum-=a[i-k];
            ans = max(ans,sum);
        }
    }
    printf("%d\n",ans);
    return 0;
}
