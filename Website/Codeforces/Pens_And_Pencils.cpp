/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,a,b,c,d,k;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        if((int )ceil((double )a/c)+(int )ceil((double )b/d)<=k)
            printf("%d %d\n",(int )ceil((double )a/c),(int )ceil((double )b/d));
        else
            printf("-1\n");
    }
    return 0;
}