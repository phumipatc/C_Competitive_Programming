/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int l[5010],r[5010];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        l[i]=i-1,r[i]=i+1;
    l[1]=n,l[n]=n-1;
    r[1]=2,r[n]=1;
    int now=n,ans=n;
    for(int i=n;i>=1;i--){
        int temp=k%i;
        for(int j=1;j<=temp;j++)    ans=r[ans];
        printf("%d\n",ans);
        l[r[ans]]=l[ans];
        r[l[ans]]=r[ans];
        ans=l[ans];
    }
    return 0;
}
/*

*/
