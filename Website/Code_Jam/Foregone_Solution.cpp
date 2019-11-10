/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
int main(){
    int q,n,countt,ch;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf(" %s",a+1);
        n = strlen(a+1),countt = 1,ch = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == '4'){
                b[countt++] = '1';
                a[i] = '3';
                ch = 1;
            }else if(ch){
                b[countt++] = '0';
            }
        }
        b[countt] = NULL;
        printf("Case #%d: %s %s\n",x,a+1,b+1);
    }
	return 0;
}
