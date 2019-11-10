#include <bits/stdc++.h>
#define N 1000009
using namespace std;
int s[N],f[N];
int main()
{
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r; scanf("%d%d",&l,&r);
        s[l]++; f[r]++;
    }
    for(int i=1;i<N;i++){
        s[i]+=s[i-1]; f[i]+=f[i-1];
    }
    int m; scanf("%d",&m);
    while(m--){
        int l,r; scanf("%d%d",&l,&r); // [l,r]
        printf("%d\n",s[r]-f[l-1]);
    }
    return 0;
}
