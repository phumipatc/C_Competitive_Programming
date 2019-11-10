/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110];
int main(){
    int n,l,r,lena,lenb;
    scanf("%d %s",&n,a+1);
    lena = strlen(a+1);
    for(int i=1;i<=lena;i++){
        if(a[i] == '*'){
            l = i-1,r = lena-i;
            break;
        }
    }
    // printf("%d %d\n",l,r);
    while(n--){
        scanf(" %s",b+1);
        lenb = strlen(b+1);
        if(lenb<lena-1){
            printf("No\n");
            continue;
        }
        // printf("%d\n",lenb-r+1);
        if(!strncmp(a+1,b+1,l) && !strncmp(a+l+2,b+lenb-r+1,r)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
	return 0;
}
