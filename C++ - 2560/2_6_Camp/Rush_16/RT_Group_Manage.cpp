/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[3005];
int main(){
    int n,minn,maxx,sum,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        maxx = a[i];
        minn = a[i];
        sum = a[i];
        ans++;
        for(int j=i+1;j<=n;j++){
            maxx = max(maxx,a[j]);
            minn = min(minn,a[j]);
            sum+=a[j];
            if(sum == ((minn+maxx)*(maxx-minn+1))/2)  ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
