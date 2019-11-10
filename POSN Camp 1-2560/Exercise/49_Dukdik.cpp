/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[600000],b[600000];
int aa[60],bb[60];
int main(){
    int q,i,j,lena,lenb,ch;
    scanf("%d",&q);
    while(q--){
        memset(aa,0,sizeof aa);
        memset(bb,0,sizeof bb);
        scanf(" %s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        for(i=0;i<lena;i++){
            if(isupper(a[i]))   aa[a[i]-'A']=1;
            else                    aa[a[i]-'a'+26 ]=1;
        }
        for(i=0;i<lenb;i++){
            if(isupper(b[i]))   bb[b[i]-'A']=1;
            else                    bb[b[i]-'a'+26 ]=1;
        }
        for(i=0;i<52;i++)
            if(bb[i]==1 && aa[i]==1)
                aa[i]=0;
        ch=1;
        for(i=0;i<52;i++)
            if(aa[i]==1)
                ch=0;
        if(ch)  printf("LOSE\n");
        else{
            printf("WIN ");
            for(i=0;i<lena;i++){
                if(isupper(a[i]))   j=a[i]-'A';
                else                    j=a[i]-'a'+26;
                if(aa[j]==1){
                    if(j<26)    printf("%c",j+'A');
                    else            printf("%c",j+'a'-26);
                    aa[j]=0;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
