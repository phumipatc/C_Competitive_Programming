/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1100][20];
int mark[1100];
int main()
{
    int n,m,i,k,now=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf(" %s",str[i]);
    for(int i=0;i<m;i++){
        scanf("%d",&k);
        int countt=0;
        while(mark[now%n]==1)   now++;
        while(countt!=k+1){
            if(mark[now%n]==0)  countt++;
            now++;
        }
        printf("%s\n",str[(now-1)%n]);
        mark[(now-1)%n]=1;
    }
    return 0;
}
