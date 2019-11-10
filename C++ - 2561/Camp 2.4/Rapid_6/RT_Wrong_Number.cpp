/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0,num,p,sum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        p = num%10;
        num/=10;
        sum = 1;
        for(int i=1;i<=p;i++)
            sum*=num;
        ans+=sum;
    }
    printf("%d\n",ans);
	return 0;
}
