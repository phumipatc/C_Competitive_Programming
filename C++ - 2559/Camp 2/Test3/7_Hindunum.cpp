#include<bits/stdc++.h>
using namespace std;
int num[1000010][30],a[1000010],ans[1000010];
int main()
{
    int n,z,r,i,j;
    scanf("%d",&n);
    z=n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        j=0;
        while(a[i]>0){
            r = a[i]%2;
            num[i][j++] = r;
            a[i]/=2;
        }
    }
    for(j=0;i<25;i++){
        for(j=0;j<n;j++){
            ans[j]+=num[j][i];
        }
        ans[j]%=2;
    }
    for(i=0;i<25;i++){

    }
    return 0;
}
