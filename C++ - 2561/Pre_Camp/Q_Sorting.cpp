/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int l = 0,r = n,mid;
    while(l<r){
        mid = (l+r+1)/2;
        i = 1,j = 1;
        while(i<=mid && j<=n){
            if(a[i] == b[j])    i++,j++;
            else                j++;
        }
        if(i<=mid)  r = mid-1;
        else        l = mid;
    }
    printf("%d\n",n-l);
	return 0;
}
