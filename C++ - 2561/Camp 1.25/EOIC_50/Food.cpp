/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,mark[10],ans[10],use[10];
void permute(int state){
    if(state == n){
        for(int i=0;i<n;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return ;
    }
    if(state == 0){
        for(int i=1;i<=n;i++){
            if(use[i])  continue;
            if(mark[i]) continue;
            use[i] = 1;
            ans[state] = i;
            permute(state+1);
            use[i] = 0;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(use[i])  continue;
            use[i] = 1;
            ans[state] = i;
            permute(state+1);
            use[i] = 0;
        }
    }
}
int main(){
    int m,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        mark[num] = 1;
    }
    permute(0);
	return 0;
}
