/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],countt[200010];
vector<int > incr,decr;
int main(){
    int n,ch = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        countt[a[i]]++;
        if(countt[a[i]]>2){
            ch = 0;
        }
    }
    if(!ch){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(countt[a[i]] == 2)   incr.push_back(a[i]);
        else                    decr.push_back(a[i]);
        countt[a[i]]--;
    }
    printf("%d\n",incr.size());
    for(auto x:incr)
        printf("%d ",x);
    printf("\n");
    printf("%d\n",decr.size());
    for(int i=decr.size()-1;i>=0;i--)
        printf("%d ",decr[i]);
	return 0;
}
