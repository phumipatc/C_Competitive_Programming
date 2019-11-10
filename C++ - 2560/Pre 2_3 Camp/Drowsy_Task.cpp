/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100100],c1,c2;
long long A[30][30],mic[30];
int main(){
    long long k,i,j;
    scanf(" %s %lld",str,&k);
    long long len=strlen(str);
    for(i=0;i<k;i++){
        scanf(" %c %c",&c1,&c2);
        A[c2-'a'][c1-'a']=1;
        A[c1-'a'][c2-'a']=1;
    }
    for(i=0;i<len;i++){
        long long tmp=mic[str[i]-'a'];
        for(j=0;j<26;j++)
            if(A[str[i]-'a'][j]==0 && str[i]-'a'!=j)
                mic[str[i]-'a']=max(mic[j]+1,mic[str[i]-'a']);
        mic[str[i]-'a']=max(mic[str[i]-'a'],tmp+1);
    }
    long long ans=1e9;
    for(i=0;i<len;i++)
        ans=min(ans,len-mic[str[i]-'a']);
    printf("%lld\n",ans);
    return 0;
}
