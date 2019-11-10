/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20001],mark[20001];
int main(){
    int q,ch,n;
    scanf("%d",&q);
    while(q--){
        ch = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
            if(a[i] == 2 && a[i+1] == 2)
                ch = 1;
        if(ch)  printf("Invalid\n");
        else    printf("Valid\n");
    }
    return 0;
}
