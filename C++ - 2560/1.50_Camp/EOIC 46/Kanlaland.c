/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<cstdio>
using namespace std;
struct P
{
    long long power,n,root;
    long long family;
};

P a[10100];
long long findroot(long long x)
{
    long long node = x,par;
    while(node != a[node].root)
    {
        node = a[node].root;
    }
    while(node != a[x].root)
    {
        par = a[x].root;
        a[x].root = node;
        x = par;
    }
    return node;
}
void updatePower(long long winner,long long loser)
{
    a[winner].power += a[loser].power;
    a[winner].family += a[loser].family+1;
    a[loser].root = winner;
}
void sol()
{
    long long x,y;
    scanf("%lld %lld",&x,&y);
    long long rootx = findroot(x);
    long long rooty = findroot(y);
    if (rootx == rooty)
    {
        printf("Family don\'t need to make war\n");
        return ;
    }
    if(a[rootx].power > a[rooty].power)
    {
        updatePower(rootx,rooty);
        printf("Winner Family %lld\n",rootx);
    }
    else if(a[rootx].power < a[rooty].power)
    {
        updatePower(rooty,rootx);
        printf("Winner Family %lld\n",rooty);
    }
    else
    {
        if(a[rootx].family>a[rooty].family)
        {
            updatePower(rootx,rooty);

            printf("Winner Family %lld\n",rootx);
        }
        else if(a[rootx].family < a[rooty].family)
        {
            updatePower(rooty,rootx);

            printf("Winner Family %lld\n",rooty);
        }
        else
        {
            printf("Draw\n");
        }
    }
    return ;
}
int main()
{
    long long n,q;
    long long powerempoy,empoy;
    scanf("%lld %lld",&n,&q);
    for(long long i = 1; i<=n; i++)
    {
        scanf("%lld %lld",&powerempoy,&empoy);
        a[i].power = powerempoy*empoy;
        a[i].root = i;
        a[i].family = 0;
    }
    for(long long i = 1; i<=q ; i++)
    {
        printf("Day: %lld\n",i);
        sol();
    }

    return 0;
}
