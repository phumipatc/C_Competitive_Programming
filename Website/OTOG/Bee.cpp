/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[30][5];
int main(){
    ans[0][0] = ans[0][1] = 1;
    for(int i=1;i<=24;i++){
        ans[i][0] = 1;
        ans[i][1] = 1+ans[i-1][1]+ans[i-1][2];
        ans[i][2] = ans[i-1][1];
    }
    int n;
    scanf("%d",&n);
    while(n!=-1){
        printf("%d %d\n",ans[n][1],ans[n][0]+ans[n][1]+ans[n][2]);
        scanf("%d",&n);
    }
	return 0;
}