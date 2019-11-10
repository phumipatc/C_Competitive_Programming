/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char ans[25],a[25];
int main(){
    int n,maxx = 0,use,have,countt,all = 0;
    scanf("%d",&n);
    while(n--){
        scanf(" %s %d %d",a+1,&use,&have);
        countt = 0;
        while(have>=use){
            have-=use;
            have+=2;
            countt++;
        }
        all+=countt;
        if(countt>maxx){
            maxx = countt;
            strcpy(ans+1,a+1);
        }
    }
    printf("%d\n%s\n",all,ans+1);
	return 0;
}