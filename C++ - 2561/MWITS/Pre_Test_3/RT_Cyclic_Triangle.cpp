/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,q,minn,i,j,now,pass,temp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        while(q--){
            scanf("%d %d",&i,&j);
            now = 1;
            minn=i;
            minn=min(minn,n-i-1);
            minn=min(minn,j-i);
            minn=min(minn,n-j-1);
            temp = minn*3;
            pass = n;
            for(int k=1;k<=temp;k++,pass--){
                now+=pass,now%=10;
            }
            pass = n-temp;
            // printf("%d %d\n",now,pass);
            if(i == minn)           printf("%d\n",(now+j-(2*minn))%10);
            else if(minn == n-j-1)  printf("%d\n",(now+i+pass-minn-1)%10);
            else                    printf("%d\n",(now+pass+(pass-1)+n-i-(2*minn)-2)%10);
        }
    }
	return 0;
}
