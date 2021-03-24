/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	:
	Status	: Unfinished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 0;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}

#include "guess.h"
vector<int > pos,temp;
vector<pair<int ,char > > q;
char ans;
void k1(){
	while(pos.size()>1){
		q.clear();
		for(int i=0;i<pos.size();i++){
			switch(i%3){
				case 0:	q.push_back({pos[i],'R'});		break;
				case 1:	q.push_back({pos[i]-1,'R'});	break;
			}
		}
		// for(auto x:q)
		// 	printf("%d %c\n",x.first,x.second);
		// printf("\n");
		ans = ask(q);
		temp.clear();
		if(ans == 'R'){
			pos.clear();
			for(int i=0;i<q.size();i+=2)
				pos.push_back(q[i].first);
		}else if(ans == 'C'){
			pos.clear();
			for(int i=1;i<q.size();i+=2)
				pos.push_back(q[i].first+1);
		}else if(ans == 'X'){
			for(int i=0;i<pos.size();i++)
				if(i%3 == 2)
					temp.push_back(pos[i]);
			pos = temp;
		}
	}
}
void k2(){
	while(pos.size()>1){
		q.clear();
		for(int i=0;i<pos.size();i++){
			switch(i%4){
				case 0:	q.push_back({pos[i],'R'});		break;
				case 1:	q.push_back({pos[i],'B'});		break;
				case 2:	q.push_back({pos[i]-1,'R'});	break;
			}
		}
		// for(auto x:q)
		// 	printf("%d %d\n",x.first,x.second);
		// printf("\n");
		ans = ask(q);
		if(ans == 'R'){
			pos.clear();
			for(auto x:q){
				if(x.second == 'B')	continue;
				pos.push_back(x.first);
			}
		}else if(ans == 'B'){
			pos.clear();
			for(auto x:q){
				if(x.second == 'R')	continue;
				pos.push_back(x.first);
			}
		}else if(ans == 'C'){
			pos.clear();
			for(int i=2;i<q.size();i+=3)
				pos.push_back(q[i].first+1);
		}else if(ans == 'X'){
			for(int i=0;i<pos.size();i++)
				if(i%4 == 3)
					temp.push_back(pos[i]);
			pos = temp;
		}
	}
}
int find_answer(int N, int K) {
	if(K == 1){
		for(int i=0;i<N;i+=4)
			q.push_back({i,'R'});
		// for(auto x:q)
		// 	printf("%d %d\n",x.first,x.second);
		// printf("\n");
		ans = ask(q);
		pos.clear();
		if(ans == 'R'){
			for(auto x:q)
				pos.push_back(x.first);
			k1();
		}else if(ans == 'C'){
			for(auto x:q){
				if(x.first-1>=0)	pos.push_back(x.first-1);
				if(x.first+1<N)		pos.push_back(x.first+1);
			}
			k1();
		}else if(ans == 'X'){
			int last;
			for(int i=2;i<N;i+=4)
				pos.push_back(i),last = i+1;
			if(last+1 == N)	pos.push_back(last);
			k1();
		}
		return pos[0];
	}else{
		for(int i=0;i<N;i+=4){
			if((i/4)%2)	q.push_back({i,'B'});
			else		q.push_back({i,'R'});
		}
		// for(auto x:q)
		// 	printf("%d %d\n",x.first,x.second);
		// printf("\n");
		ans = ask(q);
		pos.clear();
		if(ans == 'R'){
			for(int i=0;i<q.size();i+=2)
				pos.push_back(q[i].first);
			k2();
		}else if(ans == 'B'){
			for(int i=1;i<q.size();i+=2)
				pos.push_back(q[i].first);
			k2();
		}else if(ans == 'C'){
			for(auto x:q){
				if(x.first-1>=0)	pos.push_back(x.first-1);
				if(x.first+1<N)		pos.push_back(x.first+1);
			}
			k2();
		}else if(ans == 'X'){
			int last;
			for(int i=2;i<N;i+=4)
				pos.push_back(i),last = i+1;
			if(last+1 == N)	pos.push_back(last);
			k2();
		}
		return pos[0];
	}
}

//grader
static int n, m, k;
static int cnt;

char ask(const vector<pair<int, char>> V) {
  cnt++;
  if (V.empty()) {
    return 'X';
  }
  assert(V.begin()->first >= 0 and V.rbegin()->first < n);
  for (int i = 0; i < V.size(); ++i) {
    if (i) {
      assert(V[i-1].first < V[i].first);
    }
    if (k == 1) {
      assert(V[i].second == 'R');
    } else {
      assert(V[i].second == 'R' or V[i].second == 'B');
    }
  }
  vector<char> tmp(n);
  for (auto x : V) {
    tmp[x.first] = x.second;
  }
  for (int i = 0; i < n; ++i) {
    if (tmp[i] == 0) {
      tmp[i] = 'X';
      if (i != 0) {
        if (tmp[i - 1] == 'R' or tmp[i - 1] == 'B') {
          tmp[i] = 'C';
        }
      }
      if (i != n - 1) {
        if (tmp[i + 1] == 'R' or tmp[i + 1] == 'B') {
          tmp[i] = 'C';
        }
      }
    }
  }
  return tmp[m];
}

int main() {
  assert(scanf("%d %d %d", &n, &m, &k) == 3);
  assert(m >= 0 and m < n);
  assert(k == 1 or k == 2);
	int result = find_answer(n, k);
  if (result == m) {
    printf("Correct!\n");
  } else {
    printf("Wrong! %d\n",result);
  }
  printf("called %d times\n", cnt);
	return 0;
}
