/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int LIS[1000010];
int main(){
    int n,temp,idx,maxx = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        idx = upper_bound(LIS,LIS+maxx,temp)-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = temp;
    }
    printf("%d\n",n-maxx);
	return 0;
}
