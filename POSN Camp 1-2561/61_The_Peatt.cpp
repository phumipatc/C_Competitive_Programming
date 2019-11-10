/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[52],b[55],c[55];
int main(){
    int q,len,sum,temp,ch;
    scanf("%d",&q);
    while(q--){
        ch = 1;
        scanf(" %s",a+1);
        len = strlen(a+1);
        if(len%3 == 1)      strcpy(b+1,"00"),strcat(b+1,a+1);
        else if(len%3 == 2) strcpy(b+1,"0"),strcat(b+1,a+1);
        else                strcpy(b+1,a+1);
        if(len%2 == 1)  strcpy(c+1,"0"),strcat(c+1,a+1);
        else            strcpy(c+1,a+1);
        sum = 0;
        len = strlen(b+1);
        for(int i=len,now=1;i>=1;i-=3,now^=1){
            temp = ((b[i-2]-'0')*100)+((b[i-1]-'0')*10)+b[i]-'0';
            if(now == 0)    temp*=-1;
            sum+=temp;
        }
        if(sum%7 == 0){
            printf("7 * %d\n",sum/7);
            ch = 0;
        }
        len = strlen(a+1);
        sum = 0;
        for(int i=len,now=1;i>=1;i--,now^=1){
            temp = a[i]-'0';
            if(now == 0)    temp*=-1;
            sum+=temp;
        }
        if(sum%11 == 0){
            printf("11 * %d\n",sum/11);
            ch = 0;
        }
        len = strlen(c+1);
        sum = 0;
        for(int i=len;i>=1;i-=2){
            temp = ((c[i-1]-'0')*10)+c[i]-'0';
            sum+=temp;
        }
        if(sum%99 == 0){
            printf("99 * %d\n",sum/99);
            ch = 0;
        }
        if(ch)  printf("%s\n",a+1);
    }
	return 0;
}