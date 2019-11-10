/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[20];
int n;
void permute(int now){
    if(now == n+1){
        printf("%s\n",a+1);
        return ;
    }
    for(int i=0;i<26;i++){
        a[now] = 'a'+i;
        permute(now+1);
        a[now] = 'A'+i;
        permute(now+1);
    }
    for(int i=0;i<10;i++){
        a[now] = '0'+i;
        permute(now+1);
    }
}
int main(){
    freopen("Password_List.txt","w",stdout);
    scanf("%d",&n);
    permute(1);
	return 0;
}
