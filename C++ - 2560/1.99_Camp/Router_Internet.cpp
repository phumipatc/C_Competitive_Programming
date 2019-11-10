/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
int a[100100];
using namespace std;
int main()
{
    int i,mid,r,l,n,m,c=0,now;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]),a[i]*=10;
    sort(a,a+m);
    l=0,r=2000000000;
    while(l<r){
        mid=(l+r)/2;
        now=a[0]+mid,c=1;
        for(i=1;i<m;i++){
            if(now+mid<a[i]){
                c++,now=a[i]+mid;
            }
        }
        if(c<=n)    r=mid;
        else        l=mid+1;
    }
    printf("%d.%d\n",r/10,r%10);
    return 0;
}
