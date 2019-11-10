/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,st,en,maxx = -1e9,num,minn = 0,idx = 0,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        sum+=num;
        if(maxx<sum-minn){
            maxx = sum-minn;
            st = idx+1,en = i;
        }
        if(minn>sum)    minn = sum,idx = i;
    }
    printf("%d %d\n%d\n",st,en,maxx);
	return 0;
}
