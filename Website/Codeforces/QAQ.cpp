/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[110];
int qs[110];
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    scanf(" %s",a+1);
    n = strlen(a+1);
    for(int i=1;i<=n;i++)
        if(a[i] == 'Q')
            qs[i]++;
    for(int i=1;i<=n;i++)
        qs[i]+=qs[i-1];
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i]!='A')   continue;
        ans+=qs[i-1]*(qs[n]-qs[i]);
    }
    printf("%d\n",ans);
    return 0;
}