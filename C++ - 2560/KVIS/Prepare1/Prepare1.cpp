#include<bits/stdc++.h>
using namespace std;
int a[100005];
pair<int,int> ans;
int main(){
    int q,n,countt;
//    freopen("1.in","r",stdin);
//    freopen("1.sol","w",stdout);
    cin >> q;
    while(q--){
        cin >> n;
        countt = 0;
        ans.first = ans.second = 0;
        for(int i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(a[i]!=a[i+1]){
                countt++;
                if(countt>ans.second){
                    ans.first = a[i];
                    ans.second = countt;
                }
                countt = 0;
            }else
                countt++;
        }
        printf("%d\n",ans.first);
    }
    return 0;
}
