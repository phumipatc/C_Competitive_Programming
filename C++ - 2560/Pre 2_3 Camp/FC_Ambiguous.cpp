/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define hashsize 500009
char hashh[50][hashsize][60];
char str[10005];
char ans[60];
int main()
{
    long long n,i,len,countt,q,j,k,temp;
    scanf("%lld",&n);
    while(n--)
    {
        scanf(" %s",str);
        len=strlen(str);
        countt=0;
        for(i=0;i<len;i++)
        {
            countt*=29;
            countt+=str[i]-'a';
            countt%=hashsize;
        }
        i=1;
        while(hashh[len-1][(countt+i)%hashsize][0]!=0)
            i<<=1;
        strcpy(hashh[len-1][(countt+i)%hashsize],str);
    }
    scanf("%lld",&q);
    while(q--)
    {
        countt=0;
        scanf(" %s",str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            temp=0;
            for(j=0;j<50 && i+j<len;j++)
            {
                temp*=29;
                temp+=str[i+j]-'a';
                temp%=hashsize;
                k=1;
                while(hashh[j][(temp+k)%hashsize][0]!=0 && strncmp(hashh[j][(temp+k)%hashsize],&str[i],j+1))
                    k<<=1;
                if(!strncmp(hashh[j][(temp+k)%hashsize],&str[i],j+1))
                {
                    countt++;
                    if(countt==1)
                        strcpy(ans,hashh[j][(temp+k)%hashsize]);
                }
            }
        }
        if(countt==0)
            printf("NO\n");
        else if(countt==1)
            printf("%s\n",ans);
        else
            printf("AMBIGUOUS\n");
    }
    return 0;
}
