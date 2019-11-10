/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
bool sieve[10000100];
int main(){
    int q,n,idx;
    for(int i=3;i<=10000000;i+=2)
        sieve[i] = 1;
    prime.push_back(2);
    for(int i=3;i<=3165;i++){
        if(!sieve[i])   continue;
        for(int j=i*i;j<=10000000;j+=i)
            sieve[j] = 0;
    }
    for(int i=3;i<=10000000;i++)
        if(sieve[i])
            prime.push_back(i);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        if(n<=2)    printf("1\n");
        else{
            idx = upper_bound(prime.begin(),prime.end(),n)-prime.begin();
            printf("%d\n",n-idx+1);
        }
    }
	return 0;
}
