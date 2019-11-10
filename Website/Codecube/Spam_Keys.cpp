/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main(){
    int n,ans = 0;
    scanf("%d %s",&n,str+1);
    for(int i=1;i<=n;){
        if(!strncmp(str+i,"SPACEBAR",8))        ans++,i+=8;
        else if(!strncmp(str+i,"SHIFT",5))      ans++,i+=5;
        else if(str[i] == 'Q' || str[i] == 'W') ans++,i++;
        else if(str[i] == 'E' || str[i] == 'A') ans++,i++;
        else if(str[i] == 'S' || str[i] == 'D') ans++,i++;
        else if(str[i] == 'V')                  ans++,i++;
        else                                    i++;
    }
    printf("%d\n",ans);
	return 0;
}
