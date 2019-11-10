/*
	TASK: longest
	AUTHOR: PeaTT~
	SCHOOL: CRU
	LANG: CPP
*/
#include <bits/stdc++.h>
using namespace std;
int U[1010][1010],D[1010][1010],L[1010][1010],R[1010][1010];
char a[1010][1010];
int main(){
    int t,r,c,i,j,ma;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        memset(U,0,sizeof U);
        memset(D,0,sizeof D);
        memset(L,0,sizeof L);
        memset(R,0,sizeof R);
        ma=0;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='1')        L[i][j]=L[i][j-1]+1;
                else                    L[i][j]=0;
            }
            for(j=c;j>=1;j--){
                if(a[i][j]=='1')        R[i][j]=R[i][j+1]+1;
                else                    R[i][j]=0;
            }
        }
        for(j=1;j<=c;j++){
            for(i=1;i<=r;i++){
                if(a[i][j]=='1')        U[i][j]=U[i-1][j]+1;
                else                    U[i][j]=0;
            }
            for(i=r;i>=1;i--){
                if(a[i][j]=='1')        D[i][j]=D[i+1][j]+1;
                else                    D[i][j]=0;
            }
        }
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                ma = max(ma, max(L[i][j]+U[i][j]-1,L[i][j]+D[i][j]-1));
                ma = max(ma, max(R[i][j]+U[i][j]-1,R[i][j]+D[i][j]-1));
            }
        }
        printf("%d\n",ma);
    }
    return 0;
}
/*
2 4 5 11110 11011 01111 11110 2 5 01110 11000
*/
