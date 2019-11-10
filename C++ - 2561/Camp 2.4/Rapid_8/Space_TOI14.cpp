/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int sum[2][2010],all[2][2010],lv[2][2010],maxx[2][2010];
char a[2][2010];
int main()
{
    int n,m,nowlv,nowall,nowsum,nowmaxx,ans1,ans2,ans3,now,last;
    scanf("%d %d",&m,&n);
	ans1 = ans2 = ans3 = 0;
    for(int i=1;i<=n+1;i++){
		now = i%2;
		last = !now;
		for(int j=1;j<=m;j++)
			a[now][j] = '0';
		if(i<=n)    scanf(" %s",a[now]+1);
        for(int j=1;j<=m;j++){
            if(a[now][j] == '1')	sum[now][j] = sum[now][j-1]+1;
            else                    sum[now][j] = 0,lv[now][j] = 0,all[now][j] = 0,maxx[now][j] = 0;
        }
        for(int j=m;j>=1;){
            if(a[now][j]!='1'){
                j--;
                continue;
            }
            nowlv = nowall = 0;
            nowsum = nowmaxx = sum[now][j];
            int k;
            for(k=j;k>=1 && a[now][k] == '1';k--)
				nowmaxx = max(nowmaxx,maxx[last][k]),nowlv = max(nowlv,lv[last][k]),nowall = max(nowall,all[last][k]);
            for(k=j;k>=1 && a[now][k] == '1';k--)
				maxx[now][k] = nowmaxx,lv[now][k] = nowlv+1,all[now][k] = nowall+nowsum,sum[now][k] = nowsum;
            j = k;
        }
        for(int j=m;j>=1;){
            if(a[last][j]!='1'){
                j--;
                continue;
            }
            int k,ch = 0;
            for(k=j;k>=1 && a[last][k] == '1';k--){
                if(a[now][k] == '1')
					ch = 1;
            }
            if(!ch){
                if(all[last][j] == lv[last][j]*lv[last][j]){
                    if(sum[last][j] == lv[last][j])	ans1++;
                    else							ans3++;
                }
                else if(maxx[last][j]*maxx[last][j] == all[last][j])	ans3++;
                else													ans2++;
            }
            j = k;
        }
    }
    printf("%d %d %d\n",ans1,ans2,ans3);
    return 0;
}
/*
20 12
00000000000000000000
10000000001111111110
11000100000111111100
11101110000011111000
11000000000001110000
10000000000000100000
00000000000000000000
11111000000000100000
11111000000001110000
11111000000011111000
11111000000001110000
11111000000000100000
*/
