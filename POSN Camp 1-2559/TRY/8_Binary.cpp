#include<bits/stdc++.h>
using namespace std;
unsigned int a[40];
int main()
{
    unsigned int n;
    scanf("%d",&n);
    for(i=32;i>0;i++){
        if(n%(1<<i)==0){
            a[i]=n/(1<<i);
            n
        }
    }
    return 0;
}
