/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[50100]={1};
int main(){
    int c,n,i,num;
    scanf("%d %d",&c,&n);
    while(n--){
        scanf("%d",&num);
        for(i=c;i>=num;i--)
            if(mic[i-num]==1)
                mic[i]=1;
    }
    for(i=c;i>=0;i--){
            if(mic[i]==1){
                printf("%d\n",i);
                break;
            }
        }
return 0;
}
