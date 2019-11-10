/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,d,a,b,c,sum = 0;
    scanf("%d %d",&q,&d);
    while(q--){
        scanf("%d %d",&a,&b);
        if(abs(a-b)<=d){
            sum+=max(a,b);
        }else{
            scanf("%d",&c);
            sum+=c;
        }
    }
    printf("%d\n",sum);
	return 0;
}