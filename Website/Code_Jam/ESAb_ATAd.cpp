/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ans[110];
int main(){
	int q,n,num,l,r,same,dif,turn;
	char ret;
	scanf("%d %d",&q,&n);
	while(q--){
		same = dif = 0;
		l = 2,r = n-1,num = 3,turn = 0;

		printf("1\n");
		fflush(stdout);
		scanf(" %c",&ret);
		ans[1] = ret-'0';

		printf("%d\n",n);
		fflush(stdout);
		scanf(" %c",&ret);
		ans[n] = ret-'0';

		if(ans[1] == ans[n])	same = 1;
		else					dif = 1;

		while(l<=r){
			if(num%10 == 1){
				if(same && dif){
					printf("%d\n",same);
					fflush(stdout);
					scanf(" %c",&ret);
					num++;
					if(ans[same]!=ret-'0'){
						for(int i=1;i<=n;i++)
							ans[i]^=1;
					}
					printf("%d\n",dif);
					fflush(stdout);
					scanf(" %c",&ret);
					num++;
					if(ans[dif]!=ret-'0'){
						for(int i=1;i<=n/2;i++)
							swap(ans[i],ans[n-i+1]);
						swap(l,r);
						l = n-l+1;
						r = n-r+1;
						turn^=1;
					}
				}else if(same){
					printf("%d\n",same);
					fflush(stdout);
					scanf(" %c",&ret);
					num++;
					if(ans[same]!=ret-'0'){
						for(int i=1;i<=n;i++)
							ans[i]^=1;
					}
				}else{
					printf("%d\n",dif);
					fflush(stdout);
					scanf(" %c",&ret);
					num++;
					if(ans[dif]!=ret-'0'){
						for(int i=1;i<=n;i++)
							ans[i]^=1;
						swap(l,r);
						l = n-l+1;
						r = n-r+1;
						turn^=1;
					}
				}
			}
			if(turn == 0){
				printf("%d\n",l);
				fflush(stdout);
				scanf(" %c",&ret);
				ans[l] = ret-'0';
				if(n-l+1>r){
					if(ans[l] == ans[n-l+1])	same = l;
					else						dif = l;
				}
				l++;
				num++;
				turn = 1;
			}else{
				printf("%d\n",r);
				fflush(stdout);
				scanf(" %c",&ret);
				ans[r] = ret-'0';
				if(n-r+1<l){
					if(ans[n-r+1] == ans[r])	same = n-r+1;
					else						dif = n-r+1;
				}
				r--;
				num++;
				turn = 0;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d",ans[i]);
		printf("\n");
		fflush(stdout);
		scanf(" %c",&ret);
		if(ret == 'N')	return 0;
	}
	return 0;
}