/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
    int q,n;
    cin >> q;
    while(q--){
        cin >> a;
        n = strlen(a);
        if(n>10)    printf("%c%d%c\n",a[0],n-2,a[n-1]);
        else        printf("%s\n",a);
    }
	return 0;
}
