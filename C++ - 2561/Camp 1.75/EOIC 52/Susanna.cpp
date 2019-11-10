/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=1,ans=0;i<=n;i++,ans=0){
        for(int j=1;j<=n;j++){
            scanf("%d",&num);
            ans|=num;
        }
        printf("%d ",ans);
    }
	return 0;
}
