/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int main(){
    int q,i,j,lena,lenb,ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",a,b);
        lena = strlen(a);
        lenb = strlen(b);
        j = 0;
        for(i=0;i<lena;i++){
            ch = 0;
            for(;j<lenb;j++){
                if(a[i] == b[j]){
                    j++;
                    ch = 1;
                    break;
                }
            }
            if(!ch){
                break;
            }
        }
        if(!ch) printf("No\n");
        else    printf("Yes\n");
    }
	return 0;
}
