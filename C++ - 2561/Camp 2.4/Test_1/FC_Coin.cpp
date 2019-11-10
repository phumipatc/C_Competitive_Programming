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
    int n,i,k,q,turn,countt=0,st;
    scanf("%d",&q);
    while(q--){
       turn=1;
       scanf("%d %d",&n,&k);
       if(n<k){
           printf("B\n");
           continue;
       }
       countt=0;
       st=k;
       while(1){
           if(st==n){
               printf("B\n");
               break;
           }
           if(st>n){
               printf("A\n");
               break;
           }
           st+=(1<<countt);
           countt++;
       }
    }
    return 0;
}
/*
3
2 1
3 1
3 2
*/
