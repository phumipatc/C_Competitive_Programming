/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n%2){
        printf("%.1lf\n",(double)a[(n+1)/2]);
    }else{
        printf("%.1lf\n",(a[n/2]+a[(n/2)+1])/2.0);
    }
	return 0;
}
