/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int al[100100];
int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&al[i]);
    al[0]=0,al[n+1]=m;
    sort(al,al+n+1);
    p*=2,n+=2;
    int ans=-1;
    for(int i=p;i<n;i++)
        ans=max(ans,al[i]-al[i-p]);
    printf("%d\n",ans*ans);
    return 0;
}
