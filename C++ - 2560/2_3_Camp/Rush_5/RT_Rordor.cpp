/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[10100];
int main(){
    int now=0;
    scanf(" %s",str+1);
    int len=strlen(str+1);
    for(int i=1;i<=len;i++){
        if(str[i]=='L') now+=3,now%=4;
        if(str[i]=='R') now++,now%=4;
        if(str[i]=='B') now+=2,now%=4;
    }
    switch(now){
        case 0:printf("N"); break;
        case 1:printf("E"); break;
        case 2:printf("S"); break;
        case 3:printf("W"); break;
    }
    return 0;
}
