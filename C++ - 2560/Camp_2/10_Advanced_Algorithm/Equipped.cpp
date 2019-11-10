/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[300];
int main()
{
    int bit,n,k,i,j,p=1,cost;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++)
        p*=2;
    for(i=1;i<p;i++)
        mic[i]=1e9;
    while(n--){
        scanf("%d",&cost);
        bit=0;
        for(i=0;i<k;i++){
            scanf("%d",&j);
            bit*=2;
            bit+=j;
        }
        for(i=0;i<p;i++){
            if(mic[i]!=1e9 && mic[i]+cost<mic[i|bit]){
                mic[i|bit]=mic[i]+cost;
            }
        }
    }
    printf("%d\n",mic[p-1]);
    return 0;
}
/*
5 3
10 1 0 1
30 0 1 1
5 1 0 0 0
4 0 0 1
150 1 1 1
*/
