/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int > heap;
int a[1010][1010],r[1010][2],c[1010][2];
int main(){
    int n,m,sum,ans = 1e9;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            heap.push(-a[i][j]);
        }
        r[i][0] = -heap.top();
        heap.pop();
        r[i][1] = -heap.top();
        while(!heap.empty())    heap.pop();
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            heap.push(-a[i][j]);
        }
        c[j][0] = -heap.top();
        heap.pop();
        c[j][1] = -heap.top();
        while(!heap.empty())    heap.pop();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum = a[i][j];
            if(a[i][j] == r[i][0])  sum+=r[i][1];
            else                    sum+=r[i][0];
            if(a[i][j] == c[j][0])  sum+=c[j][1];
            else                    sum+=c[j][0];
            ans = min(ans,sum);
        }
    }
    printf("%d\n",ans);
	return 0;
}
