/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d/%d",&a,&b);
        while(a!=1 ||    b!=1){
            if(a>b){
                printf("R");
                a-=b;
                swap(a,b);
            }else{
                printf("L");
                swap(a,b);
                a--;
            }
        }
    }
    return 0;
}
