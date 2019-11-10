/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[45000];
int main()
{
    int i,q,n;
    a[0]=0,a[1]=0,a[2]=2;
    for(i=3;i<=45000;i++)
        a[i]=a[i-1]+2;
    for(i=3;i<=45000;i++)
        a[i]+=a[i-1];
    //printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[5]);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=45000;i++){
            if(pow(i,2)>n){
                i--;
                //printf("%d %d %.0f\n",i,a[i],n-pow(i,2));
                printf("%.0f\n",a[i]+(n-pow(i,2)));
                break;
            }
        }
    }
    return 0;
}
