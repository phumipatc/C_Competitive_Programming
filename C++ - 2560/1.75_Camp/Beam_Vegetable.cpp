/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#define MAX 10000001 //10^7
using namespace std;
vector<char> sieve(MAX,1);
vector<int> nPrime(MAX);
void genSieve(){
    int m = sqrt(MAX);
    for(int i=2;i<m;++i){
        if(sieve[i]){
            for(int j=i;j*i<MAX;++j){
                sieve[j*i] = 0;
            }
        }
    }
}
void countPrime(){
    nPrime[0] = 0;
    for(int i=1;i<MAX;++i){
        if(sieve[i]){
            nPrime[i] = nPrime[i-1]+1;
        }else{
            nPrime[i] = nPrime[i-1];
        }
    }
}
int solve(int n){
    if(n==0)
        return 0;
    if(n<=2)
        return 1;
    return n-nPrime[n]+2;
}
int main(){
    genSieve();
    countPrime();
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;++t){
        int n;
        scanf("%d",&n);
        int ans = solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
