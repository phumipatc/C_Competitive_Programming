/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2555
using namespace std;
char str[1000100];
int main(){
    int len,a,b,c,d,e,f,g;
    scanf(" %s",str+1);
    len = strlen(str+1);
    a = b = c = d = e = f = g = 0;
    for(int i=1;i<=len;i++){
        if(str[i] == 'p')       a++,a%=MOD;
        else if(str[i] == 'e')  b+=a,b%=MOD;
        else if(str[i] == 'a')  c+=b,c%=MOD;
        else if(str[i] == 't')  d+=c,d%=MOD;
        else if(str[i] == 'r')  e+=d,g+=f,e%=MOD,g%=MOD;
        else if(str[i] == 'o')  f+=e,f%=MOD;
    }
    printf("%d\n",g);
	return 0;
}
