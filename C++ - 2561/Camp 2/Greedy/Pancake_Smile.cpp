/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int main(){
    int q,countt,len,ch;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        countt = ch = 0;
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int i=len;i>=1;i--){
            if(str[i] == '-')
                ch = 1;
            if(ch)
                if(str[i]!=str[i-1])
                    countt++;
        }
        printf("Case #%d: %d\n",x,countt);
    }
	return 0;
}
