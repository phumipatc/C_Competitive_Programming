/*
    AUTHOR: Magnam Caritatem
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[15];
void dom(int state,int now){
    if(state==n){
        for(int i=0;i<now;i++){
            if(a[i]==1)printf("--\n");
            else printf("||\n");
        }
        printf("E\n");
        return ;
    }
    if(state>n)return ;
    a[now]=1;
    dom(state+1,now+1);
    a[now]=2;
    dom(state+2,now+1);
}
int main(){
    scanf("%d",&n);
    dom(0,0);
	return 0;
}
/*

*/
