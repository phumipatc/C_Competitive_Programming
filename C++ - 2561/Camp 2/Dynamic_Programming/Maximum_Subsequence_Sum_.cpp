/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,maxx = -1e9,st = 1,stt,en,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        sum+=temp;
        if(sum>maxx){
            maxx = sum;
            stt = st,en = i;
        }
        if(sum<0){
            sum = 0;
            st = i+1;
        }
    }
    printf("%d %d\n%d\n",stt,en,maxx);
	return 0;
}
