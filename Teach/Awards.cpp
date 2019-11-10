/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[610],num[610];
bool mark[610];
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++){
        scanf("%d",&a[i]);
        mark[a[i]] = true;
    }
    int idx = 1;
    for(int i=2*n;i>=1;i--){
        if(mark[i] == 0){
            num[idx++] = i;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int w = 0,countt = 0;
        for(int j=1;j<=i;j++){
            w+=a[j];
            if(a[j] == 0)   countt++;
        }
        for(int j=n+i;j<=n*2;j++){
            w+=a[j];
            if(a[j] == 0)   countt++;
        }
        for(int j=1;j<=countt;j++)
            w+=num[j];
        ans = max(ans,w);
    }
    printf("%d\n",ans);
    return 0;
}