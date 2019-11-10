/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 105
int a[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int res = 0;
    for(int i=n;i>1;i-=2){
        if(i > 3)
            res += min(a[i]+a[i-1]+2*a[1],2*a[2]+a[1]+a[i]);
        else if(i == 3)
            res += min(a[i]+a[i-1]+a[1],a[2]+a[1]+a[i]);
        else
            res += a[i];
    }
    printf("%d\n",res);
    return 0;
}
