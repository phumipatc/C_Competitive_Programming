/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[1010][1010];
char a[1010];
int main(){
    int len,i,ans=1,st=0,j,k;
    scanf(" %s",&a);
    len=strlen(a);
    for(i=0;i<len;i++)
        mic[i][i]=1;
    for(i=len-2;i>=0;i--)
        if(a[i]==a[i+1])
            mic[i][i+1]=1,ans=2,st=i;
    for(k=3;k<=len;k++){
        for(i=0;i<len-k+1;i++){
            j=i+k-1;
            if(mic[i+1][j-1] && a[i]==a[j]){
                mic[i][j]=1;
                if(k>ans)
                    ans=k,st=i;
            }
        }
    }
    for(i=st;i<st+ans;i++)
        printf("%c",a[i]);
return 0;
}
