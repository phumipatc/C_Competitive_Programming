/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
double a[1010],b[1010];
int main(){
    int q,n,i,j,ans1,ans2;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        for(i=0;i<n;i++)
            scanf("%lf",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        for(i=0,j=0,ans1=0;i<n;i++)
            if(a[i]>b[j])
                ans1++,j++;
        for(i=n-1,j=n-1,ans2=0;i>=0;i--){
            if(a[i]>b[j])   ans2++;
            else            j--;
        }
        printf("Case #%d: %d %d\n",x,ans1,ans2);
    }
	return 0;
}
