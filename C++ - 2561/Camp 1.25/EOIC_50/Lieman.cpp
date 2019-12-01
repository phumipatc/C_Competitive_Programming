/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[21][21],mark[21],ans[21],num = 1e9,r = 1;
void permute(int state){
    if(state == m+1){
        int countt = 0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mark[j] == r || a[j][i] == 0)    continue;
                if(ans[i] != a[j][i]){
                    mark[j] = r;
                    countt++;
                }
            }
        }
        num = min(num,countt);
        r++;
        return ;
    }
    ans[state] = 1;
    permute(state+1);
    ans[state] = -1;
    permute(state+1);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    permute(1);
    printf("%d\n",num);
	return 0;
}
