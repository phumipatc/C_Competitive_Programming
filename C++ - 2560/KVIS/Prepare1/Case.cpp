#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100005];
int main(){
    srand(time(0));
    freopen("1.in","w",stdout);
    int q = 10;
    printf("%d\n",q);
    while(q--){
        int n = (rand()%100000)+1;
        int num = 0;
        printf("%d\n",n);
        for(int i=0;i<32;i++){
            num|=(rand()%2)<<i;
        }
        num-=1000000000;
        int need = (rand()%n)+1;
        while(need<=n/2)
            need = (rand()%n)+1;
        for(int i=0;i<need;i++){
            a[i].first = rand()+rand()+rand()+rand();
            a[i].second = num;
        }
        for(int i=need;i<n;i++){
            a[i].first = rand()+rand()+rand()+rand();
            int x = 0;
            for(int j=0;j<32;j++)
                x|=(rand()%2)<<j;
            a[i].second = x;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
            printf("%d ",a[i].second);
        printf("\n");
    }
    return 0;
}
