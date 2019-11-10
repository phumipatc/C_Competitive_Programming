/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char ans[15];
void place(int state){
    if(state>n) return ;
    if(state == n){
        for(int i=0;i<n;){
            if(ans[i] == '-')   printf("--\n"),i++;
            else                printf("||\n"),i+=2;
        }
        printf("E\n");
    }
    ans[state] = '-';
    place(state+1);
    ans[state] = '|';
    place(state+2);
}
int main(){
    scanf("%d",&n);
    place(0);
	return 0;
}
