#include<bits/stdc++.h>
using namespace std;
int a[700005];
int b[700005];
int c[700005];
int fw[700005];
map <int,int> ma;
void update(int i,int val)
{
    for(;i<=700000;i+=i&-i)
        fw[i]+=val;
}
int query(int i)
{
    int sum=0;
    for(;i>0;i-=i&-i)
        sum+=fw[i];
    return sum;
}
int main()
{
    int n,m,i,j,p,q,mid,now=1,att;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(j=1;j<=m;j++){
        scanf("%d",&b[j]);
        c[j]=b[j];
    }
    sort(c+1,c+m+1);
    for(i=0;i<n;i++)
    {
        p=1,q=m+1;
        while(p<q)
        {
            mid=(p+q)/2;
            if(c[mid]+query(mid)<a[i])
                p=mid+1;
            else
                q=mid;
        }
        update(p,1);
    }
    for(i=1;i<=m;i++)
    {
        att=lower_bound(c,c+m+1,b[i])-c;
        printf("%d ",c[att]+query(att));
    }
    return 0;
}
