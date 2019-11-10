/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mi[110],mj[110],x[110][110];
int main()
{
    int r,c,t,ch;
    scanf("%d",&t);
    for(int loop=1;loop<=t;loop++){
        ch=1;
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++)
            for(int j=0;j<=c;j++)
                mi[i]=mj[j]=0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                scanf("%d",&x[i][j]);
                mi[i]=max(mi[i],x[i][j]);
                mj[j]=max(mj[j],x[i][j]);
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(x[i][j]<mi[i] && x[i][j]<mj[j])
                    ch=0;
            }
        }
        printf("Case #%d: ",loop);
        if(ch)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
