/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],b[110],c[110],d[110];
int main(){
    int n,idx1,idx2,countt,ans,x,y,temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        a[x]++,b[y]++;
        for(int j=1;j<=100;j++)
            c[j] = a[j],d[j] = b[j];
        idx1 = 1,idx2 = 100,countt = 0,ans = -1e9;
        while(countt<i){
            while(c[idx1] == 0) idx1++;
            while(d[idx2] == 0) idx2--;
            ans = max(ans,idx1+idx2);
            temp = min(c[idx1],d[idx2]);
            c[idx1]-=temp,d[idx2]-=temp,countt+=temp;
        }
        printf("%d\n",ans);
    }
	return 0;
}
