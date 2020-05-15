/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[5],inp[12],ans[12];
map<int ,int > mapp;
vector<int > v;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,temp,countt;
    cin >> q;
    while(q--){
        cin >> n;
        countt = 0;
        for(int i=1;i<=n;i++){
            cin >> inp[i];
            v.push_back(inp[i]);
        }
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for(auto x:v)
            mapp[x] = 2;
        for(int i=1;i<=n;i++){
            if(mapp[inp[i]] == 2){
                mapp[inp[i]] = 1;
                ans[i] = inp[i];
                continue;
            }
            a[1] = inp[i]/1000;
            a[2] = (inp[i]%1000)/100;
            a[3] = (inp[i]%100)/10;
            a[4] = inp[i]%10;
            for(int w=0;w<=9;w++){
                for(int x=0;x<=9;x++){
                    for(int y=0;y<=9;y++){
                        for(int z=0;z<=9;z++){
                            temp = ((a[1]+w)%10)*1000;
                            temp+=((a[2]+x)%10)*100;
                            temp+=((a[3]+y)%10)*10;
                            temp+=(a[4]+z)%10;
                            if(mapp[temp])  continue;
                            ans[i] = temp;
                            mapp[temp] = 1;
                            countt++;
                            goto nextt;
                        }
                    }
                }
            }
            nextt:;
        }
        printf("%d\n",countt);
        for(int i=1;i<=n;i++)
            printf("%04d\n",ans[i]);
        mapp.clear();
        v.clear();
    }
    return 0;
}