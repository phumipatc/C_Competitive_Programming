/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int main(){
    int n,i;
    scanf("%d",&n);

    for(i=1;i<=(int)sqrt(n);i++){
        if(n%i == 0){
            ...
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        if(ans[i]!=ans[i+1])
            printf("%d ",ans[i]);
    return 0;
}
