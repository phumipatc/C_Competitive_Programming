/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[100000100];
int main(){
    int n,idx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        idx=1;
        while(tree[idx]!=0){
            if(num>tree[idx])   idx=(idx*2)+1;
            else                idx*=2;
        }
        if(i!=1)
            printf("%d ",tree[idx/2]);
        tree[idx]=num;
    }
    return 0;
}
