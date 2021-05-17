/*
	Task	: combo
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 May 2021 [12:41]
	Algo	: Observe
	Status	: Finished
*/
#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define allst(x,y) (x).begin()+y,(x).end()
#define rmdup(x) (x).resize(unique((x).begin(),(x).end())-(x).begin())
#define sz(x) (int)(x).size()
#define decp(x) fixed << setprecision(x)
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2,c);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
#include "combo.h"
std::string guess_sequence(int N) {
	vector<char > c;
	string now;
	int ret = 0;
	now.push_back('0');
	if(press("AB")){
		if(press("A"))	now.back() = 'A';
		else			now.back() = 'B';
	}else{
		if(press("X"))	now.back() = 'X';
		else			now.back() = 'Y';
	}
	if(now.back() != 'A')	c.push_back('A');
	if(now.back() != 'B')	c.push_back('B');
	if(now.back() != 'X')	c.push_back('X');
	if(now.back() != 'Y')	c.push_back('Y');
	rep(i,2,N){
		string ask = now + c[0] + now + c[1]+c[0] + now + c[1]+c[1] + now + c[1]+c[2];
		ret = press(ask);
		if(ret == i)		now.push_back(c[0]);
		else if(ret == i+1)	now.push_back(c[1]);
		else				now.push_back(c[2]);
	}
	if(N>1){
		char last = c.back();
		c.pop_back();
		now.push_back('0');
		for(auto x:c){
			now.back() = x;
			ret = press(now);
			if(ret == N)	return now;
		}
		now.back() = last;
	}
	// cout << now << '\n';
	return now;
}

//grader.cpp
// namespace {

// constexpr int MAX_N = 2000;
// constexpr int MAX_NUM_MOVES = 8000;

// int N;
// std::string S;

// int num_moves;

// void wrong_answer(const char *MSG) {
//   printf("Wrong Answer: %s\n", MSG);
//   exit(0);
// }

// }  // namespace

// int press(std::string p) {
//   if (++num_moves > MAX_NUM_MOVES) {
//     wrong_answer("too many moves");
//   }
//   int len = p.length();
//   if (len > 4 * N) {
//     wrong_answer("invalid press");
//   }
//   for (int i = 0; i < len; ++i) {
//     if (p[i] != 'A' && p[i] != 'B' && p[i] != 'X' && p[i] != 'Y') {
//       wrong_answer("invalid press");
//     }
//   }
//   int coins = 0;
//   for (int i = 0, j = 0; i < len; ++i) {
//     if (j < N && S[j] == p[i]) {
//       ++j;
//     } else if (S[0] == p[i]) {
//       j = 1;
//     } else {
//       j = 0;
//     }
//     coins = std::max(coins, j);
//   }
//   return coins;
// }

// int main() {
//   char buffer[MAX_N + 1];
//   if (scanf("%s", buffer) != 1) {
//     fprintf(stderr, "Error while reading input\n");
//     exit(1);
//   }
//   S = buffer;
//   N = S.length();

//   num_moves = 0;
//   std::string answer = guess_sequence(N);
//   if (answer != S) {
//     wrong_answer("wrong guess");
//     exit(0);
//   }
//   printf("Accepted: %d\n", num_moves);
//   return 0;
// }
