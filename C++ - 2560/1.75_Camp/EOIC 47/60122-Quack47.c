/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,q,n,countt=0;
    double num;
    scanf("%d",&q);
    while(q--){
        countt=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            num=sqrt(i);
            if(fmod(num,1)!=0)    countt++;
        }
        printf("%d\n",countt);
    }
    return 0;
}
