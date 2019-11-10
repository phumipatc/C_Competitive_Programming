/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1100];
vector<int > v;
int main()
{
    long long n,i,bit,num,j,ans=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&num);
        bit=0;
        while(num){
            bit|=1<<(num%10);
            num/=10;
        }
        a[bit]++;
    }
    for(auto x:v){
        cout << x << endl;
    }
    for(i=0;i<1024;i++)
        for(j=i+1;j<1024;j++)
            if(i&j)
                ans+=a[i]*a[j];
    for(i=0;i<1024;i++)
        ans+=(a[i]*(a[i]-1))/2;
    printf("%lld\n",ans);
    return 0;
}
