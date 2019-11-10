/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[30];
int main(){
    int q,len;
    scanf("%d",&q);
    while(q--){
        str[0] = '0';
        scanf(" %s",str+1);
        len = strlen(str);
        next_permutation(str,str+len);
        if(str[0] == '0')
            printf("%s\n",str+1);
        else
            printf("%s\n",str);
    }
	return 0;
}
