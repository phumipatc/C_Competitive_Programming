/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[102];
int mark[102];
int main(){
    int q,len;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int i=len,countt = 1;i>=1;i--,countt++)
            if(countt%3 == 0 && i!=1)
                mark[i] = 1;
        for(int i=1;i<=len;i++){
            if(mark[i]) printf(",");
            printf("%c",str[i]);
        }
        printf("\n");
        memset(mark,0,sizeof mark);
    }
	return 0;
}
