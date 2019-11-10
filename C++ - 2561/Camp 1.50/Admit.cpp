/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][25],b[100100];
int lena[110],dp[100100];
int main(){
    int n,lenb;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        lena[i] = strlen(a[i]);
    }
    cin >> b+1;
    lenb = strlen(b+1);
    dp[0] = 1;
    for(int i=1;i<=lenb;i++){
        for(int j=1;j<=n;j++){
            if(lena[j]>i)   continue;
            if(!strncmp(&b[i-lena[j]+1],a[j],lena[j])){
                dp[i] = dp[i-lena[j]];
                if(dp[i] == 1)
                    break;
            }
        }
    }
    for(int i=lenb;i>=1;i--){
        if(dp[i]){
            printf("%d\n",i);
            break;
        }
    }
	return 0;
}
