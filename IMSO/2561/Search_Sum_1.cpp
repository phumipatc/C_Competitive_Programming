/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[100100];
int main(){
    int n,k,Q;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&qs[i]);
        if(i!=0)    qs[i]+=qs[i-1];
    }
    while(k--){
        scanf("%d",&Q);
        int now = upper_bound(qs,qs+n,Q)-qs;
        printf("%d\n",now);
    }
    return 0;
}
