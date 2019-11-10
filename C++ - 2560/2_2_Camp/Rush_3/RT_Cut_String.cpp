/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[300100];
long long countt[30],ch[300100],ans[300100];
bool cmp(long long A,long long B)
{
    return A > B;
}
int main(){
    scanf(" %s",str);
    long long i,j,len=strlen(str),idx=0;
    for(i=0;i<len;i++){
        ch[str[i]-'a'+1]=i+1;
//        printf("%lld\n",str[i]-'a'+1);
        for(j=1;j<=26;j++){
            ans[j]=ch[j];
        }
        //ans[idx++]=0;
        sort(ans+1,ans+27,cmp);
        for(j = 1;j<=26;j++)
            countt[j] += ans[j] - ans[j+1];
//        printf("\n");
    }
    for(i=1;i<=27;i++)
        if(countt[i]==0)
            break;
    printf("%lld\n",i-1);
    for(j=1;j<i;j++)
        printf("%lld\n",countt[j]);
    return 0;
}
