/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110];
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,minn = 1000000000,temp;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        temp = 0;
        for(int j=1;j<=m;j++){
            scanf("%d",&a[j]);
            temp = max(temp,a[j]-a[j-1]);
        }
        minn = min(minn,temp);
    }
    printf("%d\n",minn);
    return 0;
}