/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000001]={1};
int main()
{
    int i,q,x;
    for(i=1;i<=100000;i++){
        a[i]=a[i-1];
        if(i%50==0)
            a[i]+=a[i-50];
        if(i%25==0)
            a[i]+=a[i-25];
        if(i%10==0)
            a[i]+=a[i-10];
        if(i%5==0)
            a[i]+=a[i-5];
        a[i]%=1000003;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        printf("%d\n",a[x]);
    }
    return 0;
}
