/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1400017
using namespace std;
char a[50];
long long hashh[MOD+10],num[MOD+10],mark[MOD+10];
int main(){
    long long q,n,len,sum,h,now,p = 1,ch;
    scanf("%lld",&q);
    for(long long i=1;i<10;i++)
        p*=29;
    while(q--){
        scanf("%lld",&n);
        for(int x=1;x<=n;x++){
            scanf(" %s",a+1);
            len = strlen(a+1);
            sum = 0;
            if(len == 44){
                for(long long i=1;i<=len;i++){
                    sum = (sum*29)+(a[i]-'a');
                    if(i>=10){
                        h = sum%MOD;
                        while(hashh[h]){
                            if(hashh[h] == sum+1)   break;
                            h = (h+1)%MOD;
                        }
                        if(mark[h]!=x){
                            mark[h] = x;
                            hashh[h] = sum+1;
                            num[h]++;
                        }
                        sum-=(a[i-9]-'a')*p;
                    }
                }
            }else{
                for(long long i=1;i<=len;i++)
                    sum = (sum*29)+(a[i]-'a');
                h = sum%MOD,ch = 0;
                while(hashh[h]){
                    if(hashh[h] == sum+1){
                        if(num[h] == 1) ch = 1;
                        else            ch = 2;
                        break;
                    }
                    h = (h+1)%MOD;
                }
                if(!ch)             printf("not exist\n");
                else if(ch == 1)    printf("unique\n");
                else                printf("duplicate\n");

            }
        }
        memset(hashh,0,sizeof hashh);
        memset(num,0,sizeof num);
        memset(mark,0,sizeof mark);
    }
	return 0;
}
