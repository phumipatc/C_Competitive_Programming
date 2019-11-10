/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[25],price[25],sett[5],mark[25];
int main(){
    int k,setprice,n,num;
    scanf("%d",&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&price[i]);
    scanf("%d",&setprice);
    for(int i=1;i<=4;i++){
        scanf("%d",&sett[i]);
        mark[sett[i]]=1;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        countt[num]++;
    }
    int ans=0,now,minn;
    for(int i=1;i<=k;i++)
        if(!mark[i])
            ans+=price[i]*countt[i],countt[i]=0;
//    printf("[%d]\n",ans);
    for(int temp=1;temp<=4;temp++){
        minn=1e9,now=0;
        for(int i=1;i<=k;i++){
            if(countt[i]){
                now+=price[i];
                minn=min(minn,countt[i]);
            }
        }
        if(now>setprice)    ans+=(setprice*minn);
        else                ans+=(now*minn);
//        printf("[%d]\n",ans);
        for(int i=1;i<=4;i++)
            if(countt[sett[i]])
                countt[sett[i]]-=minn;
    }
    printf("%d\n",ans);
    return 0;
}
/*
6
12 5 7 8 9 3
14
4 3 1 2
5
1 2 1 6 6
*/
