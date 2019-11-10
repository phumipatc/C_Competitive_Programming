/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110];
int main(){
    int q,k,len,countt;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf(" %s %d",a+1,&k);
        len = strlen(a+1),countt = 0;
        for(int i=1;i<=len-k+1;i++){
            if(a[i] == '+') continue;
            countt++;
            for(int j=0;j<k;j++){
                if(a[i+j] == '+')   a[i+j] = '-';
                else                a[i+j] = '+';
            }
        }
        int ch = 0;
        for(int i=1;i<=len;i++){
            if(a[i] == '-'){
                ch = 1;
                break;
            }
        }
        if(ch)  printf("Case #%d: IMPOSSIBLE\n",x);
        else    printf("Case #%d: %d\n",x,countt);
    }
	return 0;
}
