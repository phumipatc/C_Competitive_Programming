/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[500100];
int main(){
    int n,m,num;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(i%2 == 1){
            countt[1]++;
            countt[num+1]--;
        }else{
            countt[m-num+1]++;
            countt[m+1]--;
        }
    }
    int ans = 1e9,now = 0;
    for(int i=1;i<=m;i++){
        countt[i]+=countt[i-1];
        if(ans>countt[i]){
            ans = countt[i];
            now = 1;
        }else if(ans == countt[i])  now++;
    }
    printf("%d %d\n",ans,now);
	return 0;
}
