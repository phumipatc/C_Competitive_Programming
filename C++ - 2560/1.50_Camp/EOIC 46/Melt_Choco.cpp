/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int play(int num,int index,long long l,long long r){
    while(l<=r){
        long long mid = (l+r)>>1;
        if(mid==index){
            return num&1;
        }
        else if(mid<index){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
        num>>=1;
    }
}

int calRange(int n){
    int range = 1;
    while(n>1){
        range = (range<<1)+1;
        n/=2;
    }
    return range ;
}

int main(){
    //freopen("10.in","r",stdin);
    //freopen("10.sol","w",stdout);
    int n,l,r; scanf("%d %d %d",&n,&l,&r);
    int range = calRange(n);
    int res = 0;
	//printf("%d\n",range);
    for(int i=l;i<=r;i++){
        res += play(n,i,1,range);
    }
    printf("%d\n",res);
    return 0;
}
