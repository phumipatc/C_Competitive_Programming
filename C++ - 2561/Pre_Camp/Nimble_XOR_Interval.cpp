/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[130];
int main(){
    int q,n,m,temp,qx;
    long long ans;
    scanf("%d",&q);
    while(q--){
        countt[0] = 1,ans = qx = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&temp);
            qx^=temp;
            for(int j=0;j<128;j++){
                if((qx^j)>=m)
                    ans+=countt[j];
            }
            countt[qx]++;
        }
        printf("%lld\n",ans);
        memset(countt,0,sizeof countt);
    }
	return 0;
}
