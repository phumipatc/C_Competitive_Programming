/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[100100];
int main()
{
    int q,z,m,i,j;
    for(i=0;i<=100000;i++)
        mic[i]=100;
    mic[0]=0;
    for(i=0;i<=100000;i++){
        for(j=1;j<=317;j++)
            if(i+j*j<=100000)
                mic[i+j*j]=min(mic[i+j*j],mic[i]+1);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&z,&m);
        printf("%d\n",mic[z]%m);
    }
    return 0;
}
