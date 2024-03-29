/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
int n,m,c;
struct A{
    int a[210][210];
    A operator * (const A&o){
        A temp;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                temp.a[i][j] = 0;
                for(int k=1;k<=n;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                    temp.a[i][j]%=MOD;
                }
            }
        }
        return temp;
    }
};
A p[32],ans;
int main(){
    int u,v;
    scanf("%d %d %d",&n,&m,&c);
    while(m--){
        scanf("%d %d",&u,&v);
        p[0].a[u][v] = p[0].a[v][u] = 1;
    }
    for(int i=1;i<=n;i++)
        p[0].a[i][i] = 1;
    for(int i=1;i<=30;i++)
        p[i] = p[i-1]*p[i-1];
    ans.a[1][1] = 1;
    for(int i=0;i<=30;i++){
        if((1<<i) & c){
            ans = ans*p[i];
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans.a[1][i]);
	return 0;
}
/*
5 5 3
1 2
2 3
2 4
3 5
4 5
*/