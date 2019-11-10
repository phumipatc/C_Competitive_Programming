/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010];
int modd(int len){
    int now = 1,sum = 0;
    while(now<=len){
        sum*=10,sum+=a[now]-'0';
        sum%=4;
        now++;
    }
    return sum;
}
int main(){
    int q,n,sum,len,temp;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a+1);
        len = strlen(a+1);
        sum = 1;
        if((a[len]-'0')%2)  sum+=4;
        else                sum++;
        temp = modd(len);
        if(temp == 1)       sum+=5;
        else if(temp == 2)  sum+=8;
        else if(temp == 3)  sum+=5;
        else                sum+=2;
        sum%=5;
        printf("%d\n",sum);
    }
	return 0;
}
