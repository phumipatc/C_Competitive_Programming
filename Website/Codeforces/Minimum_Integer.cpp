/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,l,r,d,num;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&l,&r,&d);
        if(d<l){
            printf("%d\n",d);
            continue;
        }
        num = ((r/d)+1)*d;
        printf("%d\n",num);
    }
	return 0;
}
