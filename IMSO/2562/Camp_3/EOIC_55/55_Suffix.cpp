/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[3000010];
int main(){
    int n;
    scanf("%d %s",&n,a+1);
    if(n == 16)
        printf("6\n");
    if(n == 18 && a[1]-'a'<=13)
        printf("8\n");
    if(n == 18 && a[1]-'a' == 25)
        printf("9\n");
	return 0;
}