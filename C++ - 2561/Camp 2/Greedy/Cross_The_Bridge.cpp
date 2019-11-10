/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
int main(){
    int n,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>1;i-=2){
        if(i > 3)
            ans += min(a[i]+a[i-1]+(2*a[1]),a[1]+a[i]+(2*a[2]));
        else if(i == 3)
            ans += a[1]+a[2]+a[3];
        else
            ans += a[i];
    }
    printf("%d\n",ans);
    return 0;
}
