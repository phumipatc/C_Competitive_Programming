/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[10],ans[10],use[10],n;
void permute(int state){
    if(state == n){
        for(int i=0;i<state;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return ;
    }
    if(state == 0){
        for(int i=1;i<=n;i++){
            if(mark[i]) continue;
            ans[state] = i;
            use[i] = 1;
            permute(state+1);
            use[i] = 0;
        }
        return ;
    }
    for(int i=1;i<=n;i++){
        if(use[i])  continue;
        ans[state] = i;
        use[i] = 1;
        permute(state+1);
        use[i] = 0;
    }
}
int main(){
    int m,temp;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> temp;
        mark[temp] = 1;
    }
    permute(0);
	return 0;
}
