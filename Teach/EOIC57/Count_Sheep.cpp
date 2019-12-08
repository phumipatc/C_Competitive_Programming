/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int mark[12];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,mul,ch;
    long long now;
    cin >> q;
    for(int x=1;x<=q;x++){
        cin >> n;        
        if(n == 0)  cout << "Case #" << x << ": INSOMNIA\n";
        else{
            cout << "Case #" << x << ": ";
            mul = 1;
            while(1){
                ch = 1;
                for(int i=0;i<=9;i++){
                    if(!mark[i]){
                        ch = 0;
                        break;
                    }
                }
                if(ch){
                    now = (long long )n*(mul-1);
                    cout << now << "\n";
                    break;
                }
                now = (long long )n*mul;
                while(now>=1){
                    mark[now%10] = 1;
                    now/=10;
                }
                mul++;
            }
            memset(mark,0,sizeof mark);
        }
    }
    return 0;
}