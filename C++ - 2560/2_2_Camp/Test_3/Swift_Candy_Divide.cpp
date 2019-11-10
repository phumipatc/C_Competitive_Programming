/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int candy[300100];
int main(){
    int a,b,l=1,r;
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;i++){
        scanf("%d",&candy[i]);
        r=max(r,candy[i]);
    }
    while(l<r){
        int mid=(l+r)/2;
        int countt=0;
        for(int i=1;i<=b;i++)
            countt+=(int)ceil((double)candy[i]/mid);
        if(countt>a)
            l=mid+1;
        else
            r=mid;
    }
    printf("%d\n",l);
    return 0;
}
