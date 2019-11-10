/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
struct A{
    int a[210][210];
};
A temp;
int n,m,t;
void multi(A *a,A *b){
    memset(temp.a,0,sizeof temp.a);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                temp.a[i][j]+=a->a[i][k]*b->a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
}
A a[35];
A ans;
int main(){
    int i;
    scanf("%d %d %d",&n,&m,&t);
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        a[0].a[u][v]=a[0].a[v][u]=1;
    }
    for(i=1;i<=n;i++)
        a[0].a[i][i]=ans.a[i][i]=1;
    for(i=1;i<=31;i++){
        multi(&a[i-1],&a[i-1]);
        a[i]=temp;
    }
    for(i=0;i<=31;i++){
        if(t&(1<<i)){
            multi(&ans,&a[i]);
            ans=temp;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",ans.a[i][1]);
    return 0;
}
