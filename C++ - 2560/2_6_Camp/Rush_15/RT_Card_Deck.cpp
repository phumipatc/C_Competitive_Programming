/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[5][15],ans[5] = {13,13,13,13,13};
char str[1005];
int main(){
    scanf(" %s",str+1);
    int len = strlen(str+1),num;
    for(int i=1;i<=len;i+=3){
        if(str[i] == 'P'){
            num = ((str[i+1]-'0')*10)+(str[i+2]-'0');
            if(mark[1][num] == 1){
                printf("Wrong\n");
                return 0;
            }
            mark[1][num] = 1;
            ans[1]--;
        }else if(str[i] == 'K'){
            num = ((str[i+1]-'0')*10)+(str[i+2]-'0');
            if(mark[2][num] == 1){
                printf("Wrong\n");
                return 0;
            }
            mark[2][num] = 1;
            ans[2]--;
        }else if(str[i] == 'H'){
            num = ((str[i+1]-'0')*10)+(str[i+2]-'0');
            if(mark[3][num] == 1){
                printf("Wrong\n");
                return 0;
            }
            ans[3]--;
            mark[3][num] = 1;
        }else if(str[i] == 'T'){
            num = ((str[i+1]-'0')*10)+(str[i+2]-'0');
            if(mark[4][num] == 1){
                printf("Wrong\n");
                return 0;
            }
            ans[4]--;
            mark[4][num] = 1;
        }
    }
    for(int i=1;i<5;i++)
        printf("%d ",ans[i]);
    return 0;
}
