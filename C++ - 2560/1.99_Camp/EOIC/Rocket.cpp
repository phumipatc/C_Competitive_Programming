/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int st[50100],en[50100];
int main()
{
    int n,m,i,j,x,countt=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d %d",&st[i],&en[i]);
    }
    for(i=0;i<m;i++){
        scanf("%d",&x);
        for(j=0;j<n;j++){
            if(x>st[j] && x<en[j])
                countt++;
        }
    }
    printf("%d\n",countt);
    return 0;
}
