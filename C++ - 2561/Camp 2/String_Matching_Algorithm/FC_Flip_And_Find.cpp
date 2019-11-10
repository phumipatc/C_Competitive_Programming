/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100010],b[1010][12],opr[5];
int mark[2060],pat[2060];
int main(){
    int n,lena,lenb,sum = 0,countt = 0,st,en,q,pos;
    scanf("%d %d %d %s",&n,&lenb,&lena,a+1);
    for(int i=1;i<=lena;i++){
        sum = (sum<<1)+(a[i]-'0');
        if(i>=lenb){
            mark[sum]++;
            sum = sum-((a[i-lenb+1]-'0')*(1<<(lenb-1)));
        }
    }
    for(int i=1;i<=n;i++){
        scanf(" %s",b[i]+1);
        sum = 0;
        for(int j=1;j<=lenb;j++)
            sum = (sum<<1)+(b[i][j]-'0');
        countt+=mark[sum];
        pat[sum] = 1;
    }
    scanf("%d",&q);
    while(q--){
        scanf(" %s",opr);
        if(opr[1] == 'i'){
            printf("%d\n",countt);
        }else{
            scanf("%d",&pos);
            pos++;
            st = max(1,pos-lenb+1);
            en = min(lena,pos+lenb-1);
            sum = 0;
            for(int i=st;i<=en;i++){
                sum = (sum<<1)+(a[i]-'0');
                if(i-st+1>=lenb){
                    mark[sum]--;
                    if(pat[sum])    countt--;
                    sum = sum-((a[i-lenb+1]-'0')*(1<<(lenb-1)));
                }
            }
            a[pos] = ('1'-a[pos]) + '0';
            sum = 0;
            for(int i=st;i<=en;i++){
                sum = (sum<<1)+(a[i]-'0');
                if(i-st+1>=lenb){
                    mark[sum]++;
                    if(pat[sum])    countt++;
                    sum = sum-((a[i-lenb+1]-'0')*(1<<(lenb-1)));
                }
            }
        }
    }
	return 0;
}
/*
3 5 30
010100101010111101010101110100
11010
10101
00100
8
find
flip 10
find
flip 22
find
flip 6
flip 5
find
*/
