/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > prime;
bool mark[100010];
void simpleSieve(int limit) 
{ 
    bool mark[limit + 1]; 
    memset(mark, false, sizeof(mark)); 
    for (int i = 2; i <= limit; ++i) { 
        if (mark[i] == false) { 
            prime.push_back(i); 
            for (int j = i; j <= limit; j += i) 
                mark[j] = true; 
        } 
    } 
} 
  
void prime_in_range(int low, int high) 
{ 
    int limit = floor(sqrt(high)) + 1; 
    simpleSieve(limit); 
    int n = high - low + 1; 
    memset(mark, false, sizeof(mark)); 
    for (int i = 0; i < prime.size(); i++) { 
        int loLim = floor(low / prime[i]) * prime[i]; 
        if (loLim < low) 
            loLim += prime[i]; 
        if(loLim==prime[i]) 
            loLim += prime[i]; 
        for (int j = loLim; j <= high; j += prime[i]) 
            mark[j - low] = true; 
    }
    prime.clear();
    for (int i = low; i <= high; i++) 
        if (!mark[i - low] && i!=1) 
            printf("%d\n",i);
} 
  
int main(){
    int q,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&l,&r);
        prime_in_range(l,r);
    }
    return 0;
}
