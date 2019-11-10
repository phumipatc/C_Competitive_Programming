/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int main(){
    int n,len,countt = 0,ch;
    scanf("%d",&n);
    while(n){
        scanf(" %s",a+1);
        len = strlen(a+1);
        ch = 1;
        for(int i=1;i<=len;i++){
            if(isdigit(a[i])){
                ch = 0;
                break;
            }
        }
        if(!isupper(a[1]))   ch = 0;
        countt+=ch;
        if(a[len] == '.' || a[len] == '?' || a[len] == '!'){
            n--;
            printf("%d\n",countt);
            countt = 0;
        }
    }
	return 0;
}