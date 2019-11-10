/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010],b[1000010],temp[1000010];
int KMP[1000010],jump[1000010];
int main(){
    int q,lena,lenb,i,j,now;
    scanf("%d",&q);
    while(q--){
        scanf("%s %s",a+1,b+1);
        lena = strlen(a+1);
        lenb = strlen(b+1);
        j = 0,now = 1;
        for(i=2;i<=lenb;i++){
            while(j>0 && b[i]!=b[j+1])    j = KMP[j];
            if(b[i] == b[j+1])    j++;
            KMP[i] = j;
        }
        j = 0;
        for(i=1;i<=lena;i++){
            while(j>0 && a[i]!=b[j+1]) j = KMP[j];
            if(a[i] == b[j+1]) j++;
            temp[now] = a[i];
            jump[now] = j;
            now++;
            if(j == lenb){
                now-=lenb;
                temp[now] = NULL;
                j = jump[now-1];
            }
        }
        temp[now] = NULL;
        if(now == 1)
            printf("No COI Secret Code\n");
        else
            printf("%s\n",temp+1);
    }
    return 0;
}
