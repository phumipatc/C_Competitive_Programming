/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[500500],b[500500],d[500500];
int c[150];
int main(){
    int n,i,lena,lenb,count,ch;
    scanf("%d",&n);
    while(n--){
        scanf(" %s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        memset(c,0,sizeof c);
        for(i=0;i<lenb;i++)
            c[(int)b[i]]=1;
        for(i=0,count=0,ch=0;i<lena;i++){
            if(c[(int)a[i]]==0){
                d[count++]=a[i];
                c[(int)a[i]]=1;
                ch=1;
            }
        }
        if(ch){
            printf("WIN ");
            for(i=0;i<count;i++)
                printf("%c",d[i]);
                printf("\n");
        }else{
            printf("LOSE");
        }
    }
return 0;
}
