/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[500100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&p[i].first,&p[i].second);
        if(i == 1 || p[i].second<=p[i-1].second){
            printf("0\n");
        }else{
            printf("%d\n",p[i].second-p[i-1].second);
            p[i].second = p[i-1].second;
        }
    }
    return 0;
}
