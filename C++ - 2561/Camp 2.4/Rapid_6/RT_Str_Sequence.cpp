/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
string temp;
unordered_map<string ,int > mapp;
char a[2000010];
int main(){
    int n,len,tempp,maxx = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a+1);
        len = strlen(a+1),tempp = 1;
        temp.clear();
        for(int j=1;j<=len;j++){
            temp.push_back(a[j]);
            if(mapp[temp] && !strncmp(a+1,a+len-j+1,j)){
                tempp = max(tempp,mapp[temp]+1);
            }
        }
        mapp[temp] = tempp;
        maxx = max(maxx,tempp);
    }
    printf("%d\n",maxx);
	return 0;
}
