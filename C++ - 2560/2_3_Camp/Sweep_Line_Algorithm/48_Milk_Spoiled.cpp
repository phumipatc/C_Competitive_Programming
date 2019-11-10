/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int low[1000100],high[1000100];
int main(){
    int q,n,x,y,z;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&n,&x,&y,&z);
        for(int i=0;i<n;i++)
            scanf("%d %d",&low[i],&high[i]);
        sort(low,low+n);
        sort(high,high+n);
        low[n]=high[n]=1e9;
        int now=(n*x);
        int i=0,j=0,maxx=-1;
        while(i<n || j<n){
            if(low[i]<=high[j])
                now+=y-x,i++;
            else
                now+=z-y,j++;
            maxx=max(maxx,now);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
