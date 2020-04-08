/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int st,en,id;
	bool operator < (const A&o) const{
		if(st!=o.st)		return st<o.st;
		else if(en == o.en)	return en<o.en;
		else				return id<o.id;
	}
};
A a[1010];
char ans[1010];
int main(){
	int q,n,J,C,pos;
	scanf("%d",&q);
	for(int x=1;x<=q;x++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d %d",&a[i].st,&a[i].en),a[i].id = i;
		sort(a+1,a+n+1);
		J = C = 0,pos = 1;
		for(int i=1;i<=n;i++){
			if(C<=a[i].st){
				C = a[i].en;
				ans[a[i].id] = 'C';
				continue;
			}
			if(J<=a[i].st){
				J = a[i].en;
				ans[a[i].id] = 'J';
				continue;
			}
			pos = 0;
			break;
		}
		ans[n+1] = '\0';
		printf("Case #%d: ",x);
		if(!pos)	printf("IMPOSSIBLE\n");
		else		printf("%s\n",ans+1);
	}
	return 0;
}