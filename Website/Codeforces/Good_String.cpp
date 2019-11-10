/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char temp;
int main(){
    int q,n,pos1,pos2;
    cin >> q;
    while(q--){
        cin >> n;
        pos1 = 1e9;
        pos2 = -1e9;
        for(int i=1;i<=n;i++){
            cin >> temp;
            if(temp == '>') pos1 = min(pos1,i);
            else            pos2 = max(pos2,i);
        }
        printf("%d\n",min(pos1-1,n-pos2));
    }
	return 0;
}
