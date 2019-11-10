/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
// #include<conio.h>
using namespace std;
char str[2010],ans;
vector<int > p[5010],pos,lar,sma,st;
void multi(int now){
	int temp = 0;
	for(auto x:p[now-1]){
		p[now].push_back(((x*2)+temp)%10);
		if(((x*2)+temp)>=10)	temp = 1;
		else					temp = 0;
	}
	if(temp)	p[now].push_back(1);
}
void substract(int n){
	sma.clear();
	lar.clear();
	for(auto x:pos)
		sma.push_back(x);
	pos.clear();
	for(auto x:p[n])
		lar.push_back(x);
	for(int i=0;i<lar.size();i++){
		if(lar[i]<0)	lar[i+1]--,lar[i]+=10;
		if(i>=sma.size()){
			pos.push_back(lar[i]);
			continue;
		}
		if(lar[i]>=sma[i]){
			pos.push_back(lar[i]-sma[i]);
		}else{
			lar[i]+=10,lar[i+1]--;
			pos.push_back(lar[i]-sma[i]);
		}
	}
	while(!pos.empty() && pos[pos.size()-1] == 0)	pos.pop_back();
}
int comp(int n){
	if(p[n].size()>pos.size())		return -1;
	else if(p[n].size()<pos.size())	return 1;
	else{
		for(int i=pos.size()-1;i>=0;i--){
			if(pos[i]>p[n][i])		return 1;
			else if(pos[i]<p[n][i])	return -1;
		}
		return 0;
	}
}
void fold(int n){
	int mid = n-1,ch;
	ch = comp(mid);
	// printf("%d %d ",n,ch);
	// for(int i=pos.size()-1;i>=0;i--)
	// 	printf("%d",pos[i]);
	// printf("\n");
	if(ch == 0){
		ans = 'D';
	}else if(ch == -1){
		fold(mid);
	}else if(ch == 1){
		substract(n);
		fold(mid);
		if(ans == 'D')	ans = 'U';
		else			ans = 'D';
	}
}
int main(){
    int n,len;
    scanf("%d %s",&n,str+1);
	len = strlen(str+1);
	for(int i=len;i>=1;i--)
		pos.push_back(str[i]-'0'),st.push_back(str[i]-'0');
	p[0].push_back(1);
	for(int i=1;i<=n;i++)
		multi(i);
	fold(n);
	printf("%c",ans);
	while(!pos.empty())	pos.pop_back();
	for(auto x:st)
		pos.push_back(x);
	pos[0]++;
	for(int i=0;i<pos.size();i++){
		if(pos[i] == 10){
			if(i == pos.size()-1)	pos.push_back(1),pos[i] = 0;
			else					pos[i+1]++,pos[i] = 0;
		}else	break;
	}
	fold(n);
	printf("%c",ans);
	while(!pos.empty())	pos.pop_back();
	for(auto x:st)
		pos.push_back(x);
	pos[0]+=2;
	for(int i=0;i<pos.size();i++){
		if(pos[i]>=10){
			if(i == pos.size()-1)	pos.push_back(1),pos[i]%=10;
			else					pos[i+1]++,pos[i]%=10;
		}else	break;
	}
	fold(n);
	printf("%c",ans);
	return 0;
}
