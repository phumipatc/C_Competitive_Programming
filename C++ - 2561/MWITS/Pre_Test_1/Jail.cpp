/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1000010];
int main(){
    int n,m,now = 1,temp = 0;
    cin >> n >> m;
    int countt = n;
    while(countt){
        if(!mark[now])  temp++;
        if(temp == m){
            temp = 0;
            mark[now] = 1;
            printf("%d ",now);
            countt--;
        }
        now++;
        if(now == n+1)  now = 1;
    }
	return 0;
}
