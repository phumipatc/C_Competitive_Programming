/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> mapp;
string str;
int main(){
    int q,n,m,countt;
    scanf("%d",&q);
    while(q--){
        countt = 0;
        scanf("%d %d",&n,&m);
        while(m--){
            cin >> str;
            if(!mapp[str])  mapp[str] = 1,countt++;
        }
        if(countt == n)
            printf("yes\n");
        else
            printf("no\n");
        mapp.clear();
    }
	return 0;
}
