/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> a;
int gcd(int a,int b){
    if(a%b==0)  return b;
    return gcd(b,a%b);
}
int main(){
    int q,n,i,j,temp,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        if(n<=3){
            printf("NO\n");
            continue;
        }
        a.clear();
        temp=n;
        for(i=2;i<10000;i++){
            if(n%i==0){
                for(j=0;n%i==0;j++,n/=i);
                a.push_back(j);
            }
        }
        ans=a[0];
        for(i=0;i<a.size();i++)
            ans=gcd(ans,a[i]);
        if(ans==1 || n!=1)  printf("NO\n");
        else                printf("%d\n",ans);
    }
	return 0;
}
