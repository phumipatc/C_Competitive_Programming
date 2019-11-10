/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],lu[100010],ld[100010],ru[100010],rd[100010],dp[100010][2];
int main()
{
    int q,n,i,st,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        lu[1] = ld[1] = 1;
        for(int i=2;i<=n;i++){
            lu[i] = ld[i] = 1;
            if(a[i]-a[i-1]>=1 && a[i]-a[i-1]<=2)
                lu[i]+=lu[i-1];
            if(a[i-1]-a[i]>=1 && a[i-1]-a[i]<=2)
                ld[i]+=ld[i-1];
        }
        rd[n] = ru[n] = 1;
        for(int i=n-1;i>=1;i--){
            rd[i] = ru[i] = 1;
            if(a[i]-a[i+1]>=1 && a[i]-a[i+1]<=2)
                rd[i]+=rd[i+1];
            if(a[i+1]-a[i]>=1 && a[i+1]-a[i]<=2)
                ru[i]+=ru[i+1];
        }
        for(int i=1;i<=n;i++){
            dp[i][0] = max(lu[i]+rd[i]-1,ld[i]+ru[i]-1);
            printf("");
        }
        cout << endl;
    }
    return 0;
}
/*
2
12
20 10 11 11 15 10 17 16 10 12 20 20
7
0 0 0 0 0 0 0
*/
