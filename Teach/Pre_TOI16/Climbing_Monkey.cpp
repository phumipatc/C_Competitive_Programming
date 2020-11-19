/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Observe
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int banana[200010];
int st[200010],en[200010];
int nst[200010];
PII a[1000010];
int main(){
    int m,n,k,x;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&banana[i]);
        st[i] = en[i] = i;
    }
    for(int i=1;i<=k;i++)
        scanf("%d %d",&a[i].second,&a[i].first);
    scanf("%d",&x);
    sort(a+1,a+k+1);
    for(int i=1;i<=k;i++){
        swap(st[en[a[i].second] ],st[en[a[i].second+1] ]);
        swap(en[a[i].second],en[a[i].second+1 ]);
    }
    for(int i=1;i<=n;i++){
        nst[i] = st[i];
        st[i] = en[i] = i;
    }
    int maxx = banana[nst[x] ],used = 0;
    for(int i=1;i<=k;i++){
        swap(st[en[a[i].second] ],st[en[a[i].second+1] ]);
        swap(en[a[i].second],en[a[i].second+1 ]);
        if(a[i].first == a[i+1].first)  continue;
        if(banana[nst[en[st[x]+1 ] ] ]>maxx){
            maxx = banana[nst[en[st[x]+1 ] ] ];
            used = 1;
        }
        if(banana[nst[en[st[x]-1 ] ] ]>maxx){
            maxx = banana[nst[en[st[x]-1 ] ] ];
            used = 1;
        }
    }
    printf("%d\n",maxx);
    printf(used?"USE\n":"NO\n");
	return 0;
}
