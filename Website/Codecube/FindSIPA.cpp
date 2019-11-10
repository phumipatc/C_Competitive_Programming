/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1005],str2[1005];
int main(){
    scanf(" %s",str+1);
    int len = strlen(str+1),countt = 0;
    for(int i=1;i<=len;i++)
        str2[i] = tolower(str[i]);
    for(int i=1;i<=len;i++){
        if(str2[i] == 's' && str2[i+1] == 'i' && str2[i+2] == 'p' && str2[i+3] == 'a'){
            printf("\"%c%c%c%c\"",str[i],str[i+1],str[i+2],str[i+3]);
            countt++;
            i+=3;
        }else
            printf("%c",str[i]);
    }
    printf("\n%d\n",countt);
    return 0;
}
