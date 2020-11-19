/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: QS
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
LL qs[2010][2010];
LL qsl[2010][2010],qsr[2010][2010];
int main(){
    int n,m,k;
	LL maxx = -1e18;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&qs[i][j]);
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            qsl[i][j] = qsl[i-1][j-1]+qs[i][j]-qs[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            qsr[i][j] = qsr[i-1][j+1]+qs[i][m]-qs[i][j-1]-qs[i-1][m]+qs[i-1][j-1];
    for(int i=k;i<=n;i++)
        for(int j=k;j<=m;j++)
            maxx = max(maxx,qsl[i][j]-qsl[i-k][j-k]-qs[i][j-k]+qs[i-k][j-k]);
    for(int i=k;i<=n;i++)
        for(int j=m-k+1;j>=1;j--)
            maxx = max(maxx,qsr[i][j]-qsr[i-k][j+k]-(qs[i][m]-qs[i-k][m]-qs[i][j+k-1]+qs[i-k][j+k-1]));
    printf("%lld\n",maxx);
	return 0;
}
/*
4 5 3
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/