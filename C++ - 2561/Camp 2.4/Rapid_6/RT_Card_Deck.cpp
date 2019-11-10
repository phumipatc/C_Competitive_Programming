/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010];
int mark[30][15];
int main(){
    int n,num,c1,c2,c3,c4;
    scanf(" %s",a+1);
    n = strlen(a+1),c1 = c2 = c3 = c4 = 13;
    for(int i=1;i<=n;i+=3){
        num = (a[i+1]-'0')*10+(a[i+2]-'0');
        if(mark[a[i]-'A'][num]){
            printf("Wrong\n");
            return 0;
        }
        mark[a[i]-'A'][num] = 1;
        if(a[i] == 'P') c1--;
        if(a[i] == 'K') c2--;
        if(a[i] == 'H') c3--;
        if(a[i] == 'T') c4--;
    }
    printf("%d %d %d %d\n",c1,c2,c3,c4);
	return 0;
}
