/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
    int n,m,p,maxx = 0;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[0] = 0,a[n+1] = m;
    sort(a,a+n+1);
    p*=2,n++;
    for(int i=p;i<=n;i++)
        maxx = max(maxx,a[i]-a[i-p]);
    printf("%d\n",maxx*maxx);
    return 0;
}
