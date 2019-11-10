/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[510][30][30],a[510];
int main(){
    int q,minn,n,i,j,k,ch;
    cin >> q;
    while(q--){
        cin >> n;
        ch=0;
        for(i=1;i<=n;i++){
            cin >> a[i];
            if(a[1]!=a[i])
                ch=1;
        }
        memset(mic,0,sizeof mic);
        for(i=1;i<=n;i++){
            for(j=0;j<=20;j++){
                for(k=0;k<=20;k++){
                    minn=1e9;
                    if(j==a[i] || k==a[i]){
                        minn = min(minn,mic[i-1][j][k]);
                    }else{
                        minn = min(minn,mic[i-1][a[i]][k]+1);
                        minn = min(minn,mic[i-1][j][a[i]]+1);
                    }
                    mic[i][j][k] = minn;
                }
            }
        }
        minn=1e9;
        for(j=0;j<=20;j++)
            for(k=0;k<=20;k++)
                minn=min(minn,mic[n][j][k]);
        if(ch==1)   printf("%d\n",minn+2);
        else        printf("%d\n",minn+1);
    }
    return 0;
}
