/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long x[100010],y[100010],p[100010][2],n,i,ans;
int main(){
	scanf("%lld",&n);
            for(i=0;i<n;i++){
                        scanf("%lld %lld",&p[i][0],&p[i][1]);
                        x[p[i][0]]++;
                        y[p[i][1]]++;
            }
            for(i=0;i<n;i++){
                        ans+= (x[p[i][0]]-1) * (y[p[i][1]]-1);
            }
            printf("%lld\n",ans);
}
