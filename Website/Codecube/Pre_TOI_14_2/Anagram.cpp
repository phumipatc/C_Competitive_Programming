/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2005],b[2005];
long long digit[27];
vector<long long > hashh;
int main(){
    long long lena,lenb,ans=-1;
    scanf(" %s %s",a+1,b+1);
    lena = strlen(a+1);
    lenb = strlen(b+1);
    digit[0] = 1;
    for(long long i=1;i<26;i++)
        digit[i] = digit[i-1]*2003;
    for(long long i=1;i<=lena;i++){
        long long sum = 0;
        for(long long j=i;j<=lena;j++){
            sum+=digit[a[j]-'A'];
            //printf("%lld",sum);
            hashh.push_back(sum);
        }
    }
    sort(hashh.begin(),hashh.end());
    for(long long i=1;i<=lenb;i++){
        long long  sum = 0;
        for(long long j=i;j<=lenb;j++){
            sum+=digit[b[j]-'A'];
            long long idx = lower_bound(hashh.begin(),hashh.end(),sum)-hashh.begin();
            if(hashh[idx] == sum)
                ans = max(ans,j-i+1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
