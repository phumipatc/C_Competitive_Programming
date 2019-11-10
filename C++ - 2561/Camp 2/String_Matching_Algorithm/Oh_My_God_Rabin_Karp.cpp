/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000003
using namespace std;
char a[1000010],b[1000010];
int main(){
    int lena,lenb,ha = 0,hb = 0,num = 1,j;
    scanf(" %s %s",a,b);
    lena = strlen(a),lenb = strlen(b);
    for(int i=0;i<lenb;i++){
        ha = ((ha*29)+(a[i]-'0'))%MOD;
        hb = ((hb*29)+(b[i]-'0'))%MOD;
    }
    for(int i=0;i<lenb-1;i++)
        num = (num*29)%MOD;
    for(int i=0;i<lena-lenb;i++){
        if(ha == hb){
            for(j=0;j<lenb;j++){
                if(b[j]!=a[i+j])    break;
            }
            if(j == lenb){
                printf("Lucky\n");
                return 0;
            }
        }
        ha-=(num*(a[i]-'0'))%MOD;
        if(ha<0)    ha+=MOD;
        ha = (ha*29)%MOD;
        ha = (ha+(a[i+lenb]-'0'))%MOD;
    }
    printf("Unlucky\n");
	return 0;
}
