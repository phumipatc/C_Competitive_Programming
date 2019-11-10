/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long t[5],n,a,b,mp[5][5]={{0,1},{2,3}};
void prescotch(long long type,long long color_A,long long color_B,long long countt_A,long long countt_B){
    for(long long i=1;i<=n;i++){
        t[type]+=(color_A|color_B);
        countt_A++;
        countt_B++;
        if(countt_A==a){
            color_A=(color_A+1)%2;
            countt_A=0;
        }
        if(countt_B==b){
            color_B=(color_B+1)%2;
            countt_B=0;
        }
    }
}
long long Get_Result(long long color_A,long long color_B,long long countt_A,long long countt_B){
    long long result=0;
    for(long long i=1;i<=n;i++){
        result+=t[mp[color_A][color_B]];
        countt_A++;
        countt_B++;
        if(countt_A==a){
            color_A=(color_A+1)%2;
            countt_A=0;
        }
        if(countt_B==b){
            color_B=(color_B+1)%2;
            countt_B=0;
        }
    }
    return result;
}
int main()
{
    scanf("%lld %lld %lld",&n,&a,&b);
    prescotch(0,0,0,0,0);
    prescotch(1,0,1,0,0);
    prescotch(2,1,0,0,0);
    prescotch(3,1,1,0,0);
//    for(int i=0;i<4;i++)    printf("%d\n",t[i]);
    printf("%lld\n",Get_Result(1,1,0,0));
    return 0;
}
