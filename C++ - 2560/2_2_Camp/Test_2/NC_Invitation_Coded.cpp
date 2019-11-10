/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1010][1010];
char str[1010],inv[1010];
int main(){
    int n,m,q=10,k,i,j,len;
    while(q--){
        scanf(" %s",str+1);
        len=strlen(str+1);
        for(i=1;i<=len;i++)
            str[i]=tolower(str[i]),inv[len-i+1]=str[i];
        memset(mic,0,sizeof mic);
        for(i=1;i<=len;i++){
            for(j=1;j<=len;j++){
                if(str[i]==inv[j])
                    mic[i][j]=mic[i-1][j-1]+1;
                mic[i][j]=max(mic[i][j],max(mic[i-1][j],mic[i][j-1]));
            }
        }
        printf("%d",mic[len][len]%10);
    }
    return 0;
}
