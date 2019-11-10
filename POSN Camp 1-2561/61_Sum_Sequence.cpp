/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[22];
int countt,n,ch;
void permute(int sum,int state){
    if(sum == 0){
        countt++;
        if(countt == n){
            for(int i=0;i<state;i++)
                printf("%d",ans[i]);
            printf("\n");
            ch = 1;
        }
        return ;
    }
    for(int i=1;i<=min(9,sum);i++){
        ans[state] = i;
        permute(sum-i,state+1);
        if(ch)  return ;
    }
}
int main(){
    int q,s;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&s,&n);
        ch = countt = 0;
        permute(s,0);
    }
	return 0;
}