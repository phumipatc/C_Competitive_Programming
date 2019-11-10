/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,l,ans[15],mark[15],countt;
void permute(int state,int last){
    if(state == k){
        countt++;
        if(countt == l){
            for(int i=0;i<k;i++)
                printf("%d ",ans[i]);
            exit(0);
        }
    }
    for(int i=last+1;i<=n;i++){
        if(!mark[i]){
            mark[i] = 1;
            ans[state] = i;
            permute(state+1,i);
            mark[i] = 0;
        }
    }
}
int main(){
    scanf("%d %d %d",&n,&k,&l);
    permute(0,0);
    return 0;
}
