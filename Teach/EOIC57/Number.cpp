/*
    AUTHOR: Phumipat C.
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],n,m;
int r = 1,start = 0;
int find_pos(int num){
	if(r)   return (num+start-1)%n;
	else    return (n+start-num+1)%n;
}
int main(){
	int i,j,k,x,y,temp;
	char c;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++){
		scanf(" %c ",&c);
		if(c == 'a'){
			scanf("%d %d",&x,&y);
			j = find_pos(x);
			k = find_pos(y);
            swap(a[j],a[k]);
		}
		else if(c == 'b'){
			scanf("%d %d",&x,&y);
			a[find_pos(x)] = y;
		}
		else if(c == 'c'){
			scanf("%d",&x);
			start = find_pos(x);
			r^=1;
		}
		else if(c == 'q'){
			scanf("%d",&x);
			printf("%d\n",a[find_pos(x)]);
		}
	}
	return 0;
}
