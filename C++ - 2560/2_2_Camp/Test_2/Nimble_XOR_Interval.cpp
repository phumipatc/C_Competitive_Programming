/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],mark[150];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m,i,j;
        long long ans=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=2;i<=n;i++)
            a[i]^=a[i-1];
        mark[0]=1;
        for(i=1;i<=n;i++){
            for(j=0;j<=127;j++){
                if(mark[j]>0){
                    if((a[i]^j)>=m){
                        ans+=mark[j];
                    }
                }
            }
//            printf("%lld\n",ans);
            mark[a[i]]++;
        }
        printf("%lld\n",ans);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
