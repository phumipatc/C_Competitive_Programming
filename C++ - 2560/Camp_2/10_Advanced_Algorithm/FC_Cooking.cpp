/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[12],b[12];
int main()
{
    int n,i,j,temp,suma,sumb,minn=1e9;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i],&b[i]);
    temp=1<<n;
    for(i=1;i<temp;i++){
        suma=1,sumb=0;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                suma*=a[j],sumb+=b[j];
            }
        }
        minn=min(minn,abs(suma-sumb));
    }
    printf("%d\n",minn);
    return 0;
}
