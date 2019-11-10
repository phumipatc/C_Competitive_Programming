/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
void A(int n){
    for(int i=1;i<=n;i++){
        printf("sin(%d",i);
        if(i == n)  continue;
        if(i%2) printf("-");
        else    printf("+");
    }
    for(int i=1;i<=n;i++)
        printf(")");
}
void S(int n){
    if(n == 0)  return ;
    for(int i=1;i<n;i++)
        printf("(");
    for(int i=1;i<n;i++){
        A(i);
        printf("+%d)",n-i+1);
    }
    A(n);
    printf("+1");
}
int main(){
    int n;
    scanf("%d",&n);
    S(n);
	return 0;
}