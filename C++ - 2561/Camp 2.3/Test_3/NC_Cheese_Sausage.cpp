/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b){
    if(a%b == 0)    return b;
    else            return GCD(b,a%b);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",b-GCD(a,b));
	return 0;
}
