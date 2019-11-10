/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > man[2],woman[2];
int main(){
    int n,temp,j,countt = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        if(temp<0)  man[0].push_back(-temp);
        else        man[1].push_back(temp);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        if(temp<0)  woman[0].push_back(-temp);
        else        woman[1].push_back(temp);
    }
    for(int i=0;i<2;i++){
        sort(man[i].begin(),man[i].end());
        sort(woman[i].begin(),woman[i].end());
    }
    j = woman[1].size()-1;
    for(int i=man[0].size()-1;i>=0 && j>=0;){
        if(woman[1][j]<man[0][i]){
            countt++;
            i--;
        }
        j--;
    }
    j = 0;
    for(int i=0;i<man[1].size() && j<woman[0].size();){
        if(woman[0][j]>man[1][i]){
            countt++;
            i++;
        }
        j++;
    }
    printf("%d\n",countt);
	return 0;
}
