/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int countt[30];
int main(){
    int q,n,minn,maxx,ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str);
        n = strlen(str),minn = 1e9,maxx = -1e9,ch = 1;
        for(int i=0;i<n;i++)    countt[str[i]-'a']++,minn = min(minn,str[i]-'a'),maxx = max(maxx,str[i]-'a');
        for(int i=minn;i<=maxx;i++){
            if(countt[i]!=1){
                ch = 0;
                break;
            }
        }
        if(ch)  printf("Yes\n");
        else    printf("No\n");
        memset(countt,0,sizeof countt);
    }
	return 0;
}
