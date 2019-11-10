/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int price[15];
char ans[120];
int main()
{
    int i,j,len,minn=1e9,num,nowprice,k;
    scanf("%d",&k);
    for(i=1;i<=9;i++){
        scanf("%d",&price[i]);
        if(price[i]<minn)
            minn=price[i],num=i;
    }
    len=k/minn;
    nowprice=len*price[num];
    for(i=1;i<=len;i++)
        ans[i]=num+'0';
    for(i=1;i<=len;i++){
        for(j=9;j>=1;j--){
            if(j>ans[i]-'0' && price[j]+nowprice-price[ans[i]-'0']<=k){
                nowprice=price[j]+nowprice-price[ans[i]-'0'];
                ans[i]=j+'0';
                break;
            }
        }
    }
    for(i=1;i<=len;i++)
        printf("%c",ans[i]);
    return 0;
}
/*
44
9
10
12
40
40
40
40
40
40
*/
