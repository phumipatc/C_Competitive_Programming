/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char minn[32],temp[32],tempp[32];
int lena;
void num(int n,int idx){
    if(n<10){
        strcpy(tempp+1,temp+1);
        temp[idx] = '0'+n;
        sort(temp+1,temp+idx+1);
        if(minn[1] == (char )NULL){
            strcpy(minn+1,temp+1);
            lena = strlen(temp+1);
            strcpy(temp+1,tempp+1);
            return ;
        }
        int lenb = strlen(temp+1);
        if(lena<lenb){
            strcpy(temp+1,tempp+1);
            return ;
        }
        if(lenb<lena || (lena == lenb && strcmp(minn+1,temp+1)>0))
            strcpy(minn+1,temp+1),lena = lenb;
        strcpy(temp+1,tempp+1);
        return ;
    }
    for(int i=2;i<=9;i++){
        if(n%i) continue;
        temp[idx] = '0'+i;
        num(n/i,idx+1);
        temp[idx] = (char )NULL;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    minn[1] = (char )NULL;
    if(n == 0)      printf("0\n");
    else{
        num(n,1);
        if(minn[1]!=(char )NULL)    printf("%s\n",minn+1);
        else                        printf("-1\n");
    }
	return 0;
}