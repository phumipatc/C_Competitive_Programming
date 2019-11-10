/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <bits/stdc++.h>
using namespace std;
int a[250100][2],b[250010][2],p[300100];
int findroot(int r){
    if(p[r]==r)
        return r;
    return p[r]=findroot(p[r]);
}
int main()
{
    int t,v,e,m,l,r,mid,roota,rootb,i,ch,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d %d %d",&v,&e,&m);
        for(i=0;i<m;i++)
            scanf("%d %d",&a[i][0],&a[i][1]);
        for(i=0;i<e;i++)
            scanf("%d %d",&b[i][0],&b[i][1]);
        l=1,r=e+1;
        while(l<r){
            mid=(l+r)/2;
            for(i=1;i<=v;i++)   p[i]=i;
            for(i=0;i<mid;i++){
                roota = findroot(b[i][0]);
                rootb = findroot(b[i][1]);
                p[roota]=rootb;
            }
            for(i=0,ch=0;i<m;i++){
                roota = findroot(a[i][0]);
                rootb = findroot(a[i][1]);
                if(roota!=rootb)
                    ch=1;
            }
            if(ch)  l=mid+1;
            else    r=mid;
        }
        if(r>e)
            printf("C#%d: -1\n",j);
        else
            printf("C#%d: %d\n",j,r);
    }
    return 0;
}
/*
1 5 5 5 1 2 1 3 3 2 4 5 2 5 1 5 2 3 1 4 1 3 2 5
*/
