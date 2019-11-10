/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,k,maxx = 0,sum,countt;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        sum = countt = 0;
        for(int j=i;j<=n;j++){
            if(sum+a[j]>k)  continue;
            sum+=a[j];
            countt++;
        }
        maxx = max(maxx,countt);
    }
    printf("%d\n",maxx);
	return 0;
}