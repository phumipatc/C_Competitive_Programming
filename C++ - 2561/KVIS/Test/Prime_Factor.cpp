/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > prime;
int cprime[10000010],countt[10000010];
int main(){
    int sq = sqrt(10000000);
    for(int i=3;i<10000000;i+=2)
        cprime[i] = 1;
    for(int i=3;i<=sq;i++){
        if(!cprime[i])  continue;
        for(int j=i*i;j<=10000000;j+=i)
            cprime[j] = 0;
    }
    prime.push_back(2);
    for(int i=3;i<=10000000;i+=2){
        if(!cprime[i])  continue;
        prime.push_back(i);
    }
    for(auto &i:prime){
        countt[i] = 1;
        for(int j=2*i;j<=10000000;j+=i)
            countt[j]++;
    }
    int q,idx,idx2,a,b,k,cou;
    cin >> q;
    while(q--){
        cin >> a >> b >> k;
        cou = 0;
        for(int i=a;i<=b;i++)
            if(countt[i] == k)
                cou++;
        printf("%d\n",cou);
    }
	return 0;
}
