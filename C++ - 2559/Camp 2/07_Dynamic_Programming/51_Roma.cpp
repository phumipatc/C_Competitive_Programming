/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[2010][2010];
char a[2010],b[2010],c[2010];
int main()
{
    int ma=0,st,i,j,lena,lenb,coun=0;
    scanf("%s %s",&a[1],&b[1]);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j]){
               mic[i][j]=mic[i-1][j-1]+1;
            }
            else{
                mic[i][j]=max(mic[i-1][j],mic[i][j-1]);
            }
        }
    }
    printf("%d\n",mic[lena][lenb]);
    if(mic[lena][lenb]==0){
        printf("No Roma word\n");   return 0;
    }
    i=lena,j=lenb;
    while(mic[i][j]>0){
        if(a[i]==b[j]){
            c[coun++]=a[i];
            i--,j--;
        }
        else{
            if(mic[i][j-1] > mic[i-1][j])
                j--;
            else if(mic[i][j-1] <= mic[i-1][j])
                i--;
        }
    }
    for(i=coun-1;i>=0;i--)
        printf("%c",c[i]);
    return 0;
}
