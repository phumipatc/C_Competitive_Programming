/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int row[100005],col[100005],tilt1[200005],tilt2[200005];
int main(){
    int n,k,x,y;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        row[x]++;
        col[y]++;
        tilt1[100000+(y-x)]++;
        tilt2[y+x]++;
        if(row[x]>=k || col[y]>=k || tilt1[100000+(y-x)]>=k || tilt2[y+x]>=k){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
