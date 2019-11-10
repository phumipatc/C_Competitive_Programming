/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int in[1000100],out[1000100];
int main(){
    int n,q,st,en;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&st,&en);
        in[st]++,out[en]++;
    }
    for(int i=1;i<=1000000;i++)
        in[i]+=in[i-1],out[i]+=out[i-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&st,&en);
        printf("%d\n",in[en]-out[st-1]);
    }
	return 0;
}
