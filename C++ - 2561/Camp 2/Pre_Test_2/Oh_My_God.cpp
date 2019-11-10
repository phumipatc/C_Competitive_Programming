/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010];
int KMP[1000010];
int main(){
    int lena,lenb,j,ch;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1);
    lenb = strlen(b+1);
    j = 0;
    for(int i=2;i<=lenb;i++){
        while(j>0 && b[j+1]!=b[i])  j = KMP[j];
        if(b[j+1] == b[i])  j++;
        KMP[i] = j;
    }
    j = ch = 0;
    for(int i=1;i<=lena;i++){
        while(j>0 && b[j+1]!=a[i])  j = KMP[j];
        if(b[j+1] == a[i])  j++;
        if(j == lenb){
            ch = 1;
            break;
        }
    }
    if(ch)  printf("Lucky\n");
    else    printf("Unlucky\n");
	return 0;
}
