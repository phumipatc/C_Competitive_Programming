/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,n,sum = 0,num;
    scanf("%d %d",&k,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        sum+=k;
        sum-=num;
    }
    printf("%d\n",sum+k);
	return 0;
}