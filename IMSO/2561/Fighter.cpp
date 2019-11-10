/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,i,h1,h2,countt1 = 0,countt2 = 0,n;
    scanf("%d",&p);
    h1 = h2 = p;
    for(i=0;i<2*p;i++){
        scanf("%d",&n);
        if(n%2 == 0){
            countt1++;
            countt2 = 0;
            if(countt1<3)   h2--;
            else            h2-=3;
        }else{
            countt2++;
            countt1 = 0;
            if(countt2<3)   h1--;
            else            h1-=3;
        }
        if(h1<=0){
            printf("1\n%d",n);
            break;
        }else if(h2<=0){
            printf("0\n%d",n);
            break;
        }
    }
    return 0;
}
