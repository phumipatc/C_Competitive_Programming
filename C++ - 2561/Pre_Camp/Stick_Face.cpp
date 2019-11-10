/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[200010],a[2010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&a[i]);
        countt[1]-=2;
        countt[min(a[i],n-a[i]+1)]+=2;
        countt[min(a[i],n-a[i]+1)]--;
        countt[max(a[i],n-a[i]+1)]++;
    }
    // for(int i=1;i<=n;i++)
    //     printf("%d ",countt[i]);
    for(int i=1;i<=n;i++)
        countt[i]+=countt[i-1];
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            countt[abs(a[i]-a[j])]++;
            // printf("%d %d %d\n",a[i],a[j],abs(a[i]-a[j]));
        }
    }
    for(int i=1;i<n;i++)
        printf("%d\n",countt[i]+n-i);
	return 0;
}
