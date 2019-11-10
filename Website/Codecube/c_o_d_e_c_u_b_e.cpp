/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > pos[30];
char a[100010],temp[10];
int num[10];
int main(){
    int n,idx,ch,minn = 1e9,ans = -1;
    scanf(" %s",a+1);
    n = strlen(a+1);
    for(int i=1;i<=n;i++)
        pos[a[i]-'a'].push_back(i);
    strcpy(temp+1,"codecube");
    for(int i=1;i<=n;i++){
        if(a[i]!='c')   continue;
        idx = i;
        ch = 1;
        for(int j=2;j<=8;j++){
            idx = upper_bound(pos[temp[j]-'a'].begin(),pos[temp[j]-'a'].end(),idx)-pos[temp[j]-'a'].begin();
            if(idx == pos[temp[j]-'a'].size()){
                ch = 0;
                break;
            }
            idx = pos[temp[j]-'a'][idx];
        }
        if(!ch) continue;
        if(idx-i+1<minn){
            minn = idx-i+1;
            ans = i;
        }
    }
    if(minn == 1e9) printf("-1\n");
    else            printf("%d %d\n",ans,ans+minn-1);
	return 0;
}
