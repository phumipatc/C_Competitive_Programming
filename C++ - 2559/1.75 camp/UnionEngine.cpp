/*
TASK: Union Engine
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[30000];
int main(){
    int n,i;
    long long sum=0,ans,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    if(n==1){
        printf("%lld\n",a[0]);  return 0;
    }
    sort(a,a+n);
    ans = sum*2,temp=sum;
    for(i=0;i<n-2;i++){
        temp-=a[i];
        ans += temp;
    }
    printf("%lld\n",ans);
    return 0;
}
