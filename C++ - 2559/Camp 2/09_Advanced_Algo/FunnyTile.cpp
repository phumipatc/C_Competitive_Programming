#include<bits/stdc++.h>
using namespace std;
struct A
{
    int i,j,type;
    bool operator < (const A & b) const
    {
        if(type <   b.type)         return true;
        else if(type > b.type)      return false;
        else if(j < b.j)            return true;
        else if(j > b.j)            return false;
        else if(i < b.i)            return true;
        else                        return false;
    }
};
A ans[400000];
int cnt;
int a[1010][1010];
void divi(int n,int nex1,int nex2,int fi,int fj)
{
    int quad;
    if(fi < nex1 && fj < nex2)          quad = 1;
    else if(fi < nex1 && fj >= nex2)    quad = 2;
    else if(fi >= nex1 && fj < nex2)    quad = 3;
    else                                quad = 4;
    ans[cnt].type = quad -1,ans[cnt].i = nex1 -1,ans[cnt].j = nex2 -1,cnt++;
    if(n > 2)
    {
        if(quad == 1)       divi(n/2,nex1-n/4,nex2-n/4,fi,fj);
        else                divi(n/2,nex1-n/4,nex2-n/4,nex1 - 1,nex2 - 1);

        if(quad == 2)       divi(n/2,nex1-n/4,nex2 + n/4,fi,fj);
        else                divi(n/2,nex1-n/4,nex2 + n/4,nex1 - 1,nex2);

        if(quad == 3)       divi(n/2,nex1+n/4,nex2  - n/4,fi,fj);
        else                divi(n/2,nex1+n/4,nex2  - n/4,nex1 ,nex2 - 1);

        if(quad == 4)       divi(n/2,nex1+n/4,nex2  + n/4,fi,fj);
        else                divi(n/2,nex1+n/4,nex2  + n/4,nex1 ,nex2);
    }
}
int main()
{
    int n,sn,sm;
    scanf("%d",&n);
    scanf("%d %d",&sm,&sn);
    divi(n,n/2,n/2,sn,sm);
    sort(ans,ans+cnt);
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d %d %d\n",ans[i].type,ans[i].j,ans[i].i);
    return 0;
}
