#include<bits/stdc++.h>
using namespace std;
char str[1005];
int main(){
    int q,l,r,ch;
    freopen("1.in","r",stdin);
    freopen("1.sol","w",stdout);
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str+1);
        l = 1,r = strlen(str+1),ch = 1;
        while(l<=r){
            if(str[l]!=str[r]){
                ch = 0;
                break;
            }
            l++,r--;
        }
        if(ch)  printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
