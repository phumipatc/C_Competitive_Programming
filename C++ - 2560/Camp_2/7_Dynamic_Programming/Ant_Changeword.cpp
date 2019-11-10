/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1010][1010];
char a[1010],b[1010];
int main()
{
    int lena,lenb,i,j,q;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        for(i=1;i<=lenb;i++)
            mic[0][i]=i;
        for(i=1;i<=lena;i++)
            mic[i][0]=i;
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i]==b[j])
                    mic[i][j]=mic[i-1][j-1];
                else
                    mic[i][j]=min(mic[i-1][j-1],min(mic[i-1][j],mic[i][j-1]))+1;
            }
        }
        printf("%d\n",mic[lena][lenb]);
    }
    return 0;
}
