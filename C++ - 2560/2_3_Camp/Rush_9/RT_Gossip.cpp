/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110],l[110],r[110];
int main(){
    int n,ch=0,idx=0,lena,lenb;
    scanf("%d %s",&n,&str);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]=='*')
            ch=1,idx=0;
        else if(ch==0)
            l[idx++]=str[i];
        else if(ch==1)
            r[idx++]=str[i];
    }
    lena=strlen(l);
    lenb=strlen(r);
    while(n--){
        scanf(" %s",str);
        len=strlen(str);
        if(len<lena+lenb){
            printf("No\n");
            continue;
        }
        ch=strncmp(l,str,lena);
        if(ch!=0){
            printf("No\n");
            continue;
        }
        ch=strncmp(r,str+len-lenb,lenb);
        if(ch!=0){
            printf("No\n");
            continue;
        }
        printf("Yes\n");
    }
    return 0;
}
