/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int s[13]={0,1,2,4,5,8,9,10,16,17,18,20,21};
int mic[50010][15],a[6][50010];
int main()
{
    int q,i,j,n,ans,k,sum;
    scanf("%d",&q);
    while(q--){
        ans=0;
        memset(mic,0,sizeof mic);
        scanf("%d",&n);
        for(i=0;i<5;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++){
            for(j=0;j<13;j++){
                for(k=0,sum=0;k<5;k++){
                    if(s[j]&(1<<k))
                        sum+=a[k][i];
                }
                for(k=0;k<13;k++){
                    if(!(s[j]&s[k]))
                        mic[i+1][j]=max(mic[i+1][j],mic[i][k]+sum);
                }
            }
        }
        for(i=0;i<13;i++)
            ans=max(ans,mic[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
6
1 0 0 0 0 0
0 1 1 10 1 0
1 10 0 0 5 10
0 1 1 10 0 0
1 0 0 0 1 10
5
1 0 0 0 1
0 1 1 1 0
0 1 1 1 0
0 1 1 1 0
1 0 0 0 1
*/
