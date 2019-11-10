/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,ans = 0,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        a[num]++;
    }
    for(int i=0;i<=999;i++){
        for(int j=i;j<=999;j++){
            if(i == j){
                ans+=(a[i]*(a[i]-1))/2;
                continue;
            }
            if(i%10 == j%10 || i/100 == j/100 || (i/10)%10 == (j/10)%10)
                ans+=a[i]*a[j];
        }
    }
    printf("%d\n",ans);
	return 0;
}
