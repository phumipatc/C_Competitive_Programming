/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[5100],b[5100];
int mic[5100][5100];
int main()
{
    int q,i,lena,lenb,n,m,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i]==b[j])  mic[i][j]=mic[i-1][j-1]+1;
                else            mic[i][j]=max(mic[i-1][j],mic[i][j-1]);
            }
        }
        printf("%d",lena+lenb-mic[lena][lenb]);
    }
    return 0;
}
