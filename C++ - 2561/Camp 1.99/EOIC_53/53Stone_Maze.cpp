/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char temp;
int main(){
    int q,countt,r,c;
    scanf("%d",&q);
    while(q--){
        countt = 0;
        scanf("%d %d",&r,&c);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                scanf(" %c",&temp);
                if(temp == '.') countt++;
            }
        }
        printf("%d\n",(countt-1)*2);
    }
	return 0;
}
