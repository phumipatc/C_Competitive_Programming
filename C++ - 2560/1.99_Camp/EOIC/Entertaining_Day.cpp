/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100000000],mark[100000000],b[5100];
int main()
{
    int i,j,n,x,countt;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
        a[x]++;
    }
    for(i=1;i<n;i++){
        if(mark[a[i]]==0){
            countt++;
            printf("%d\n",countt);
            for(j=1;j<=100000000;j+=b[i]-1){
                mark[j]=1;
                printf("%d\n",j);
            }
        }
    }
    return 0;
}
