/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[2100][2100],path[2100][2100];
char a[2100],b[2100],c[2100];
int main()
{
    int i,j,lena,lenb,k=0;
    scanf(" %s %s",&a[1],&b[1]);
    lena=strlen(&a[1]);
    lenb=strlen(&b[1]);
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                mic[i][j]=mic[i-1][j-1]+1;
                path[i][j]=1;
            }else if(mic[i-1][j]>=mic[i][j-1]){
                mic[i][j]=mic[i-1][j];
                path[i][j]=2;
            }else{
                mic[i][j]=mic[i][j-1];
                path[i][j]=3;
            }
        }
    }
    printf("%d\n",mic[lena][lenb]);
    i=lena,j=lenb;
    while(i>0 && j>0){
        if(path[i][j]==1){
            c[k++]=a[i];
            i--;
            j--;
        }else if(path[i][j]==2)
            i--;
        else
            j--;
    }
    for(i=k-1;i>=0;i--)
        printf("%c",c[i]);
    printf("\n");
    if(mic[lena][lenb]==0)
        printf("No Roma word\n");
    return 0;
}
