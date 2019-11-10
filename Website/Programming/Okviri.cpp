/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[20];
int main(){
    int idx = 0,len,now = 0;
    scanf(" %s",str);
    len = strlen(str);
    printf("..");
    for(int i=0;i<((len-1)*4+1);i++){
        if(i%4 == 0){
            idx++;
            if(idx%3 == 0)  printf("*");
            else            printf("#");
        }else   printf(".");
    }
    printf("..\n");
    idx = 0;
    for(int i=0;i<=4*len;i++){
        if(i%2 == 1){
            idx++;
            if((idx+1)%6 == 0 || idx%6 == 0)  printf("*");
            else                            printf("#");
        }else   printf(".");
    }
    printf("\n");
    idx = 0;
    for(int i=0;i<=4*len;i++){
        if(i%4 == 0){
            idx++;
            if((idx%3 == 0 || (idx-1)%3 == 0) && i!=0 && (now!=len || len%3 == 0))  printf("*");
            else                                                                    printf("#");
        }else if(i%2 == 0){
            printf("%c",str[now++]);
        }else   printf(".");
    }
    printf("\n");
    idx = 0;
    for(int i=0;i<=4*len;i++){
        if(i%2 == 1){
            idx++;
            if((idx+1)%6 == 0 || idx%6 == 0)  printf("*");
            else                            printf("#");
        }else   printf(".");
    }
    printf("\n");
    idx = 0;
    printf("..");
    for(int i=0;i<((len-1)*4+1);i++){
        if(i%4 == 0){
            idx++;
            if(idx%3 == 0)  printf("*");
            else            printf("#");
        }else   printf(".");
    }
    printf("..\n");
    return 0;
}
