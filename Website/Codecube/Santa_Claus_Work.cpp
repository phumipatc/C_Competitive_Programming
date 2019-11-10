/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long i,n,ans=1;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        ans*=4;
    }
    printf("%lld\n",ans);
return 0;
}
