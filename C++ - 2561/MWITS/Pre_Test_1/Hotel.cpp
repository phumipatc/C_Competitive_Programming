/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans = 0;
    cin >> n;
    while(n>=10){
        n-=15;
        ans+=3000;
    }
    while(n>=4){
        n-=5;
        ans+=1500;
    }
    while(n>=2){
        n-=2;
        ans+=800;
    }
    if(n == 1){
        n--;
        ans+=500;
    }
    printf("%d\n",ans);
	return 0;
}
