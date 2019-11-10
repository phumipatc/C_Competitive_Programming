/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char ans[110];
void sport(int w,int l,int state){
    if(w == n || l == n){
        for(int i=0;i<state;i++)
            printf("%c ",ans[i]);
        printf("\n");
        return;
    }
    ans[state] = 'W';
    sport(w+1,l,state+1);
    ans[state] = 'L';
    sport(w,l+1,state+1);
}
int main(){
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    sport(a,b,0);
	return 0;
}
