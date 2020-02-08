/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[20];
int main(){
    int n,len,sum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a+1);
        len = strlen(a+1);
        sum = 0;
        for(int i=1;i<=len;i++){
            if(a[i] == 'J') sum++;
            if(a[i] == 'Q') sum+=2;
            if(a[i] == 'K') sum+=3;
            if(a[i] == 'A') sum+=4;
        }
        printf("%d\n",sum);
    }
	return 0;
}