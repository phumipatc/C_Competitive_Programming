/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int q,r,c,sum,n,m,ans;
    scanf("%d",&q);
    while(q--){
        sum = 0;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d %d",&r,&c);
            a[i] = r*c*(-1);
        }
        sort(a+1,a+m+1);
        for(int i=1;i<=m;i++)
            a[i]*=(-1);
        for(int i=1;i<=m;i++){
            sum+=a[i];
            if(sum>=n){
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
