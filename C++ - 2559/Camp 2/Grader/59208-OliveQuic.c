#include<bits/stdc++.h>
using namespace std;
int a[120000];
int main()
{
    int n,countt=0,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j!=i && a[i]%a[j]==0)
                countt++;
        }
        printf("%d\n",countt);
        countt=0;
    }
}
