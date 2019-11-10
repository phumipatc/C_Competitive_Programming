/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m;
        scanf("%d %d",&n,&m);
        while(m--){
            int i,j,minn,pass,last;
            scanf("%d %d",&i,&j);
            minn=i;
            minn=min(minn,n-i-1);
            minn=min(minn,j-i);
            minn=min(minn,n-j-1);
            minn=(3*minn);
            last=1;
            for(int k=n;k>n-minn;k--)
                last+=k,last%=10;
            pass=n-minn;
            printf("%d %d %d\n",minn,pass,last);
            if(i==(minn/3))
                printf("%d\n",(last+j-i-(minn/3))%10);
            else if((minn/3)==n-j-1)
                printf("%d\n",(last-1+pass+i-(minn/3))%10);
            else
                printf("%d\n",(last-1+pass+pass-1+(n-i-(2*minn/3)-1))%10);
        }
    }
    return 0;
}
