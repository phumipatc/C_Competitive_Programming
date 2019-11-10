/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100;
const int MAXLEN = 10;
int N, M;
char word[MAXN][MAXLEN + 1];
bool seen[26],great[26][26];
vector< pair< int, char > > a;

int main(void){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", word[i]);
	for (int i = 0; i < N; ++i){
		for (char *p = word[i]; *p; ++p) {
			M += !seen[*p - 'a'];
			seen[*p - 'a'] = true;
		}
	}
	//printf("%d\n",M);
	for (int i = 0; i < N - 1; ++i) {
		char *a = word[i];
		char *b = word[i + 1];
		while (*a && *b && *a == *b) {
			++a;
			++b;
		}
		if (*a && *b)
			great[*b - 'a'][*a - 'a'] = true;
		if (*a && !*b) {
			puts("!");
			return 0;
		}
	}
	for (int k = 0; k < 26; ++k)
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < 26; ++j)
				great[i][j] |= great[i][k] && great[k][j];
	for (int i = 0; i < 26; ++i)
		if (great[i][i]) {
			puts("!");
			return 0;
		}
	for (int i = 0; i < 26; ++i) {
		if (!seen[i]) continue;
		int out = 0,in = 0;
		for (int j = 0; j < 26; ++j) {
			out += great[i][j];
			in += great[j][i];
		}
		if (out + in != M - 1) {
			puts("?");
			return 0;
		}
		a.push_back(make_pair(out, 'a' + i));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < (int)a.size(); ++i)
		printf("%c", a[i].second);
	printf("\n");
	return 0;
}
