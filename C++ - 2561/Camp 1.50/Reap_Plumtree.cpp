/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
bool dp[1010],temp[1010];
int main(){
    int q,n,w,k,num,ch;
    cin >> q;
    while(q--){
        ch = -1;
        memset(dp,0,sizeof dp);
        cin >> n >> w;
        dp[0] = true;
        while(n--){
            cin >> k;
            memset(temp,0,sizeof temp);
            while(k--){
                cin >> num;
                for(int i=w;i>=num;i--){
                    if(dp[i-num])
                        temp[i] = true;
                }
            }
            for(int i=1;i<=w;i++)
                dp[i] = temp[i];
            dp[0] = 0;
        }
        for(int i=w;i>=1;i--){
            if(dp[i]){
                ch = i;
                break;
            }
        }
        printf("%d\n",ch);
    }
	return 0;
}
