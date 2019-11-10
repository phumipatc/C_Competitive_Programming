/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,g,k,sum,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&g,&k);
        sum = ans = 0;
        while(sum<g){
            if(sum+100>=g)  break;
            sum+=((k-1)*100)+10;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}