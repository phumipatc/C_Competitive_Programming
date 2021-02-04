
/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[500100];
int main(){
    int len,l,r,ch = 0,ans;
    scanf(" %s",str+1);
    len = strlen(str+1);
    for(int i=1;i<=len;i++){
        if(ch == 0 && str[i] == '['){
            ch++;
        }else if(ch == 1 && str[i] == ':'){
            ch++;
            l = i+1;
            break;
        }
    }
    ch = 0;
    for(int i=len;i>=l;i--){
        if(ch == 0 && str[i] == ']'){
            ch++;
        }else if(ch == 1 && str[i] == ':'){
            ch++;
            r = i-1;
            break;
        }
    }
    if(ch!=2){
        printf("-1\n");
        return 0;
    }
    ans = 0;
    for(int i=l;i<=r;i++){
        if(str[i] == '|')   ans++;
    }
    printf("%d\n",ans+4);
	return 0;
}
