/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
// #include<conio.h>
using namespace std;
typedef long long LL;
char a[70];
vector<int > cut[70][70];
stack<int > st;
void divide(int l,int r){
	if(l == r){
		cut[l][r].push_back(l);
		cut[l][r].push_back(r+2);
		return ;
	}
	// printf("processing: %d %d\n",l,r);
	// getch();
	int minn = 1e9;
	for(int i=l;i<=r;i++){
		if(a[i] == '('){
			minn = min(minn,4);
			while(a[i]!=')')	i++;
		}else if(a[i] == '^')	minn = min(minn,3);
		else if(a[i] == '*')	minn = min(minn,2);
		else if(a[i] == '+')	minn = min(minn,1);
	}
	if(minn == 4){
		cut[l][r].push_back(l+1);
		cut[l][r].push_back(r+1);
		divide(l+1,r-1);
		return ;
	}
	char target ;
	switch (minn)
	{
		case 1:target = '+';	break;
		case 2:target = '*';	break;
		case 3:target = '^';	break;
	}
	cut[l][r].push_back(l);
	for(int i=l;i<=r;i++){
		if(a[i] == '(')
			while(a[i]!=')')
				i++;
		if(a[i] == target){
			int last = cut[l][r][cut[l][r].size()-1];
			cut[l][r].push_back(i+1);
			divide(last,i-1);
		}
	}
	divide(cut[l][r][cut[l][r].size()-1],r);
	cut[l][r].push_back(r+2);
}
int main(){
	// freopen("1.in","r",stdin);
	int q,num,n;
	pair<int ,int > now,temp;
	scanf(" %s %d",a+1,&q);
	n = strlen(a+1);
	divide(1,n);
	while(q--){
		scanf("%d",&num);
		now = {1,n};
		int ch = 1;
		while(num!=0){
			st.push(num);
			if(ch && cut[now.first][now.second].size()>num){
				temp = {cut[now.first][now.second][num-1],cut[now.first][now.second][num]-2};
				now = temp;
			}else	ch = 0;
			// printf("%d %d\n",now.first,now.second);
			scanf("%d",&num);
		}
		temp.first = st.size();
		while(!st.empty()){
			printf("op(%d,",st.top());
			st.pop();
		}
		printf("p");
		while(temp.first--)	printf(")");
		printf("=");
		if(!ch){
			printf("null\n");
			continue;
		}
		for(int i=now.first;i<=now.second;i++)
			printf("%c",a[i]);
		printf("\n");
	}
	return 0;
}