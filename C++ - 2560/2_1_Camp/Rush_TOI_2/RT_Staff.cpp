/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int power[2000100],mic[2000100];
int main(){
    int q,n,i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&power[i]);
            mic[i] = 1e9;
        }
        mic[1] = 0;
        for(i=1;i<=n;i++){
            mic[i] = min(mic[i],mic[i-1]+1);
            if(i+power[i] <= n) mic[i+power[i]]=min(mic[i+power[i]],mic[i]+1);
        }
        printf("%d\n",mic[n]);
    }
    return 0;
}
/*
10 7
1 2 R
2 1 5
1 5 B
1 3 G
2 4 8
2 1 8
2 5 6
*/
