/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[500010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,maxx = 0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxx = max(maxx,a[i]);
    }
    int l = 1,r = maxx,mid,countt;
    while(l<r){
        mid = (l+r)/2,countt = 0;
        for(int i=1;i<=n;i++)
            countt+=ceil((double )a[i]/mid);
        // printf("%d %d\n",mid,countt);
        if(countt>m)    l = mid+1;
        else            r = mid;
    }
    printf("%d\n",l);
    return 0;
}