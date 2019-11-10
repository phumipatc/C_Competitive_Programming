/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int num[1000100];
int main()
{
    int q,n,i,maxx,add,sum;
    scanf("%d",&q);
    while(q--){
        add=sum=0;
        maxx=-1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num[i]);
            if(i%2==0)  num[i]*=-1;
            sum+=num[i];
        }
        for(i=0;i<n;i++){
            add+=num[i];
            if(add<0)   add=0;
            maxx=max(maxx,add);
        }
        printf("%d\n",sum-2*maxx);
    }
    return 0;
}
