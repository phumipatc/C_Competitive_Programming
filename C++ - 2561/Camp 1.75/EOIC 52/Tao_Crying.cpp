/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010];
vector<int > factor;
int countt[100010][30];
int main(){
    int q,len,ch;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int i=1;i<=len;i++){
            if(len%i == 0 && i!=len)
                factor.push_back(i);
            countt[i][str[i]-'a']++;
            for(int j=0;j<26;j++)
                countt[i][j]+=countt[i-1][j];
        }
        for(auto k:factor){
            ch = 1;
            for(int i=k+k;i<=len;i+=k){
                for(int j=0;j<26;j++){
                    if(countt[k][j]!=(countt[i][j]-countt[i-k][j])){
                        ch = 0;
                        goto nextt;
                    }
                }
            }
            nextt:;
            if(ch){
                for(int i=1;i<=k;i++)
                    printf("%c",str[i]);
                break;
            }
        }
        if(ch == 0) printf("-1\n");
        memset(countt,0,sizeof countt);
        factor.clear();
    }
	return 0;
}
