/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],l[1010][1010],R[1010][1010],u[1010][1010],d[1010][1010];
int main(){
    int q,r,c,maxx,sti,stj;
    cin >> q;
    while(q--){
        maxx = -1e9;
        cin >> r >> c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin >> a[i][j];
                if(j == 1)  continue;
                if(a[i][j]>=a[i][j-1])
                    l[i][j] = l[i][j-1]+1;
            }
            for(int j=c-1;j>=1;j--){
                if(a[i][j]>=a[i][j+1])
                    R[i][j] = R[i][j+1]+1;
            }
        }
        for(int j=1;j<=c;j++){
            for(int i=2;i<=r;i++){
                if(a[i][j]>=a[i-1][j])
                    u[i][j] = u[i-1][j]+1;
            }
            for(int i=r-1;i>=1;i--){
                if(a[i][j]>=a[i+1][j])
                    d[i][j] = d[i+1][j]+1;
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(maxx<u[i][j]+d[i][j]+l[i][j]+R[i][j]+1){
                    maxx = u[i][j]+d[i][j]+l[i][j]+R[i][j]+1;
                    sti = i,stj = j;
                }
            }
        }
        printf("%d\n%d %d\n",maxx,sti,stj);
        memset(u,0,sizeof u);
        memset(d,0,sizeof d);
        memset(l,0,sizeof l);
        memset(R,0,sizeof R);
    }
	return 0;
}
