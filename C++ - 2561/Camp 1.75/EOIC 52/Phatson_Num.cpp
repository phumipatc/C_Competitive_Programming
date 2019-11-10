/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,n,num,sum,minn = 1e9,maxx = 0;
    scanf("%d %d %d",&l,&r,&n);
    for(int i=l;i<=r;i++){
        num = i,sum = 0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        if(sum == n){
            minn = min(minn,i);
            maxx = max(maxx,i);
        }
    }
    printf("%d\n%d\n",minn,maxx);
	return 0;
}
