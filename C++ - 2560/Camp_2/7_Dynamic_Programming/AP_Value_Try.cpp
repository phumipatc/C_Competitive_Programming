/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
    int q,maxx,s,i,n,sum;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        sum=s=0;
        maxx=-1;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(i%2==0)  a[i]*=-1;
            sum+=a[i];
        }
        for(i=0;i<n;i++){
            s+=a[i];
            if(s<0) s=0;
            maxx=max(maxx,s);
        }
        printf("%d\n",sum-(2*maxx));
    }
    return 0;
}
