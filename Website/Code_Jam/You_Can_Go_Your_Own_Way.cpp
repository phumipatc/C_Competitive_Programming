/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010];
int main(){
    int q,n;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf("%d %s",&n,a+1);
        printf("Case #%d: ",x);
        for(int i=1;i<=2*(n-1);i++){
            if(a[i] == 'S') printf("E");
            else            printf("S");
        }
        printf("\n");
    }
	return 0;
}
