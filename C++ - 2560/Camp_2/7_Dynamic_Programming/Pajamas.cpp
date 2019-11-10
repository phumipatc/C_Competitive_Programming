/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <bits/stdc++.h>
using namespace std;
int cnt[800][800],sum[800][800];
int area(int ll, int dd, int rr, int uu) {
	return sum[rr+1][uu+1]-sum[ll][uu+1]-sum[rr+1][dd]+sum[ll][dd];
}
int main(){
	int N;
	scanf("%d", &N);
	vector<int> a(N), b(N);
	for (int i=0; i<N; i++) {
		scanf("%d %d", &a[i], &b[i]);
		cnt[a[i]][b[i]] ++;
	}
	for (int i=0; i<=700; i++)
		for (int j=0; j<=700; j++)
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + cnt[i][j];
	for (int i=0; i<N; i++) {
		int H = area(a[i]+1, b[i]+1, 700, 700) + 1;
		int L = N - area(0, 0, a[i]-1, b[i]-1);
		if (a[i] == 700) L -= cnt[0][b[i]];
		if (b[i] == 700) L -= cnt[a[i]][0];
		printf("%d %d\n", H, L);
	}
	return 0;
}
