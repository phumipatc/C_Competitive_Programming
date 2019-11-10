/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define  MAXN  0XFFFFFFF
#define  N 100010
struct Point {
    double x;
    double y;
} p[N];
int n,tmp_p[N];
bool cmpx(Point a , Point b) {
    if (a.x < b.x)  return true;
    else            return false;
}
bool cmpy(int a, int b) {
    if(p[a].y < p[b].y) return true;
    else                return false;
}
double min(double a, double b) {
    return a < b ? a : b;
}
double dis(int i, int j) {
    double tmp_x = (p[i].x - p[j].x)*(p[i].x - p[j].x);
    double tmp_y = (p[i].y - p[j].y)*(p[i].y - p[j].y);
    return sqrt(tmp_x+tmp_y);
}
double Closest_Pair(int left, int right) {
    int i, j, k = 0;
    double d = MAXN;
    if (left == right) return d;
    if (left + 1 == right) return dis(left, right);
    int mid = (left + right) >> 1;
    double d1 = Closest_Pair(left, mid);
    double d2 = Closest_Pair(mid+1, right);
    d = min(d1, d2);
    for (i = left; i <= right; i++) {
        if (fabs(p[mid].x - p[i].x) <= d)
            tmp_p[k++] = i;
    }
    sort(tmp_p, tmp_p + k, cmpy);
    for (i = 0; i < k; i++) {
        for (j = i + 1; j < k && p[tmp_p[j]].y-p[tmp_p[i]].y < d ; j++) {
            double d3 = dis(tmp_p[i], tmp_p[j]);
            if (d-d3 > 1e-9) d = d3;
        }
    }
    return d;
}

int main() {
    double MIN;
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		double R,D;
		scanf("%lf %lf\n",&R,&D);
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmpx);
        MIN = Closest_Pair(0, n-1);
        if(MIN - 2*R < D)printf("N\n");
        else             printf("Y\n");

    }
    return 0;
}
