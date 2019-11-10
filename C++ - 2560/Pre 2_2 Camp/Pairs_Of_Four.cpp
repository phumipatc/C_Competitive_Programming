/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100],mic[1100][1100];
int pick_card(int l,int r){
    if(l>=r)            return 0;
    if(mic[l][r]!=-1)   return mic[l][r];
    int maxx=-1;
    for(int i=l;i<r;i++){
        maxx=max(maxx,pick_card(l,i)+pick_card(i+1,r));
    }
    if(a[l]==a[r])  maxx=max(maxx,pick_card(l+1,r-1)+1);
    return mic[l][r]=maxx;
}
int main(){
    int n;
    char c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&c);
        a[i]=c-'A';
    }
    memset(mic,-1,sizeof mic);
    printf("%d\n",pick_card(1,n));
    return 0;
}
/*
6
U B N B O U

12
U B O U B O U B O U B O
*/
