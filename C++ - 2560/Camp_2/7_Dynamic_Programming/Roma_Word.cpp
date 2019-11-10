/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2100][2100],path[2100][2100];
char a[2100],b[2100],c[2100];
int main()
{
    int i,j,lena,lenb,k=0;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=1;i<=lena+1;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1,path[i][j]=1;
            else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j],path[i][j]=2;
            else
                dp[i][j]=dp[i][j-1],path[i][j]=3;
        }
    }
    printf("%d\n",dp[lena][lenb]);
    if(dp[lena][lenb]==0){
        printf("No Roma word\n");
        return 0;
    }
    i=lena,j=lenb;
    while(i>0 && j>0){
        if(path[i][j]==1)
            c[k++]=a[i],i--,j--;
        else if(path[i][j]==2){
            i--;
        }else
            j--;
    }
    for(i=k-1;i>=0;i--){
        printf("%c",c[i]);
    }
    return 0;
}
/*
abcbdab
bdcaba
*/
