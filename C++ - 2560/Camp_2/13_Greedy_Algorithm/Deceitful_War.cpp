/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1005

double a[N],b[N];
int n;

int game1(){
    int res = 0 ,j = n;
    for(int i=n;i>=1;i--){
        if(a[i] > b[j])
            res++;
        else
            j--;
    }
    return res;
}

int game2(){
    int res = 0 ,j = 1;
    for(int i=1;i<=n;i++){
        if(a[i] > b[j])
            res++,j++;
    }
    return res;
}

void solve(int number){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%lf",&b[i]);
    sort(&a[1],&a[1]+n);
    sort(&b[1],&b[1]+n);
    printf("Case #%d: %d %d\n",number,game2(),game1());
}

int main(){
    int Q; scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
        solve(i);
    return 0;
}
