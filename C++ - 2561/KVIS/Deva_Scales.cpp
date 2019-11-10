/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,now,countt = 0,sum = 0,v = 1;
    scanf("%d",&n);
    while(n){
        now = n%3;
        n/=3;
        if(now == 1){
            countt++,sum+=v;
        }else if(now == 2){
            countt++,n++;
        }
        v*=3;
    }
    printf("%d %d\n",countt,sum);
	return 0;
}
