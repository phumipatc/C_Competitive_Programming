/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100000100];
int main(){
    char c;
    int want,n,m,i,st,en,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&st,&en);
        a[st]++;
        a[en+1]--;
    }
    for(i=2;i<=n;i++){
        a[i]+=a[i-1];
    }
    scanf(" %c",&c);
    if(c=='R'){
        for(i=1;i<=n;i++){
            a[i]%=3;
            switch(a[i]){
            case 1:
                ans+=2;
                break;
            case 2:
                ans+=1;
                break;
            }
        }
    }else if(c=='G'){
        for(i=1;i<=n;i++){
            a[i]%=3;
            switch(a[i]){
            case 0:
                ans+=1;
                break;
            case 2:
                ans+=2;
                break;
            }
        }
    }else if(c=='B'){
        for(i=1;i<=n;i++){
            a[i]%=3;
            switch(a[i]){
            case 0:
                ans+=2;
                break;
            case 1:
                ans+=1;
                break;
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
