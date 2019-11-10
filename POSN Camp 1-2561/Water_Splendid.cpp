/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10],ans[12],final[100010][12];
int m,countt;
void permute(int sum,int state){
    if(state == m+1)    return ;
    if(sum == 0){
        final[countt][0] = state;
        for(int i=0;i<state;i++)
            final[countt][i+1] = ans[i];
        countt++;
        return ;
    }
    for(int i=1;i<=6;i++){
        if(sum-a[i]<0)  continue;
        ans[state] = a[i];
        permute(sum-a[i],state+1);
    }
}
int main(){
    int n;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=6;i++)
        scanf("%d",&a[i]);
    permute(n,0);
    printf("%d\nE\n",countt);
    for(int i=0;i<countt;i++){
        for(int j=0;j<=final[i][0];j++)
            printf("%d ",final[i][j]);
        printf("\nE\n");
    }
	return 0;
}