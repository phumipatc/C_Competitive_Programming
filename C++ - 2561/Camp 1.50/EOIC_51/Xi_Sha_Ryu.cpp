/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100100];
int a[100100];
int main(){
    int len,sum = 0;
    scanf(" %s",str);
    len = strlen(str);
    for(int i=0;i<len;i++)
        a[i] = -(str[i]-'0');
    sort(a,a+len);
    if(a[len-1] == 0){
        for(int i=0;i<len;i++)
            sum-=a[i];
        if(sum%3 == 0){
            for(int i=0;i<len;i++)
                printf("%d",-a[i]);
        }else{
            printf("-1\n");
        }
    }else{
        printf("-1\n");
    }
	return 0;
}
