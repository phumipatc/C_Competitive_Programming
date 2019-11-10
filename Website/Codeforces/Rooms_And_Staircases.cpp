/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int main(){
    int q,n,minn,maxx;
    scanf("%d",&q);
    while(q--){
        minn = 1e9,maxx = 0;
        scanf("%d %s",&n,a+1);
        for(int i=1;i<=n;i++){
            if(a[i] == '0') continue;
            minn = min(minn,i);
            maxx = max(maxx,i);
        }
        if(maxx == 0)   printf("%d\n",n);
        else            printf("%d\n",max(2*maxx,2*(n-minn+1)));
    }
    return 0;
}