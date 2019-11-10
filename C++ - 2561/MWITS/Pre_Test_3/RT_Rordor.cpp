/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[10010];
int main(){
    int len,now = 0;
    scanf(" %s",a);
    len = strlen(a);
    for(int i=0;i<len;i++){
        if(a[i] == 'L') now--;
        if(a[i] == 'R') now++;
        if(a[i] == 'B') now+=2;
    }
    now%=4;
    now+=4;
    now%=4;
    if(now == 0)    printf("N");
    if(now == 1)    printf("E");
    if(now == 2)    printf("S");
    if(now == 3)    printf("W");
	return 0;
}
