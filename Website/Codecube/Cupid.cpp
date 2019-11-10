/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int man[1005],woman[1005];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> man[i] >> woman[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=min(i+k,n);j++){
            if(man[i]<)
        }
    }
    if(man[n] == 0 && woman[n] == 0)    printf("YES\n");
    else                                printf("NO\n");
    return 0;
}
