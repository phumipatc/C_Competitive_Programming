/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a = 0,b = 0,temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        if(temp)    b = max(b,i);
        else        a = max(a,i);
    }
    printf("%d\n",min(a,b));
	return 0;
}
