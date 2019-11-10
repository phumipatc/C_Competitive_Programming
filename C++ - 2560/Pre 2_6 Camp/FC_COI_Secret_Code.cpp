/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1000010],test[1000010],Direk[1000010];
int KMP[1000010],jump[1000010];
int main(){
    int q,lena,lenb,i,j,now;
    scanf("%d",&q);
    while(q--){
        scanf("%s %s",str+1,test+1);
        lena = strlen(str+1);
        lenb = strlen(test+1);
        j = 0,now = 1;
        for(i=2;i<=lenb;i++){
            while(j>0 && test[i]!=test[j+1])    j = KMP[j];
            if(test[i] == test[j+1])    j++;
            KMP[i] = j;
        }
        j = 0;
        for(i=1;i<=lena;i++){
            while(j>0 && str[i]!=test[j+1]) j = KMP[j];
            if(str[i] == test[j+1]) j++;
            Direk[now] = str[i];
            jump[now] = j;
            now++;
            if(j == lenb){
                now-=lenb;
                Direk[now] = NULL;
                j = jump[now-1];
            }
        }
        Direk[now] = NULL;
        if(now == 1)
            printf("No COI Secret Code\n");
        else
            printf("%s\n",Direk+1);
    }
    return 0;
}
