/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main(){
    int q = 5,n,now,ch,ans;
    while(q--){
        scanf(" %s",str+1);
        n = strlen(str+1),ans = 0;
        for(int i=1;i<=n;i++){
            if(n%i) continue;
            ch = 1;
            for(int j=1;j<=n;j+=i){
                if(strncmp(str+1,str+j,i)){
                    ch = 0;
                    break;
                }
            }
            if(!ch) continue;
            ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}
