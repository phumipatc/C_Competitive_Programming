/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include <stdio.h>
#include <string.h>
long long qsA[1000005];
long long qsC[1000005];
char s[1000005];
long long q,n,i,na,nc;
long long cnt;
int main()
{
    scanf("%lld",&q);
    while(q--)
    {
        scanf(" %s",s+1);
        n=strlen(s+1);
        qsA[0]=qsC[0]=0;
        for(i=1;i<=n;i++) {
            qsA[i]=qsA[i-1];
            qsC[i]=qsC[i-1];
            if(s[i]=='A') qsA[i]++;
            if(s[i]=='C') qsC[i]++;
        }
        cnt = 0;
        for(i=1;i<=n;i++) {
            if(s[i]=='B') {
                na = qsA[i-1];
                nc = qsC[n]-qsC[i];
                cnt += na*nc;
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
