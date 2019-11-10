/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int LIS[1000010];
int main(){
    int n,num,maxx = 0,idx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        idx = upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = num;
    }
    printf("%d\n",n-maxx);
	return 0;
}
