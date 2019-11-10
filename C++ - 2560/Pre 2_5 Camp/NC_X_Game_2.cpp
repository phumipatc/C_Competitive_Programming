/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[25];
int bit[1<<21],press[1<<21],temp[1<<21];
int main(){
    int n,ans=1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",str);
        for(int j=1;j<=n;j++)
            if(str[j] == 'w')
                bit[i]|=(1<<j);
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=1;j<=n;j++){
            if(i & (1<<j)){
                press[i]^=(1<<j);
                if(j>1)
                    press[i]^=(1<<(j-1));
                if(j<n)
                    press[i]^=(1<<(j+1));
                countt[i]++;
            }
        }
    }
    if(ans == 1e9)  printf("Impossible\n");
    else            printf("%d\n",ans);
    return 0;
}
