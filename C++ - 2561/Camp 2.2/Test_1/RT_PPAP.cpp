/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long len[40];
int main(){
    long long q,n,idx,ch;
    len[0] = 1;
    for(long long i=1;i<=38;i++){
        len[i] = (len[i-1]*3)+1;
        // printf("%lld %lld\n",i,len[i]);
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        idx = lower_bound(len,len+39,n)-len,ch = 0;
        while(idx>0){
            if(n<=len[idx-1]){
                idx--;
                continue;
            }
            if(n>=len[idx]-len[idx-1]+1){
                n-=(len[idx]-len[idx-1]),idx--;
                continue;
            }
            if(n == len[idx-1]+1){
                if(ch == 1)     printf("A\n");
                else if(!ch)    printf("P\n");
                ch = 2;
                break;
            }
            ch = !ch;
            n-=(len[idx-1]+1);
            idx--;
        }
        if(ch == 1)     printf("A\n");
        else if(!ch)    printf("P\n");
    }
	return 0;
}
