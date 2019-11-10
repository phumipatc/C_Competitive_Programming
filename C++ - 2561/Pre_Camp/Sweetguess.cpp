#include<bits/stdc++.h>
using namespace std;
int prime[600100];
int main()
{
    int q,n,m,num,i,ch,j,countt;
    prime[2] = 1;
    for(i=3;i<300000;i+=2)
        prime[i] = 1;
    for(i=3;i<=sqrt(300000);i+=2){
        if(prime[i]){
            for(j=i*i;j<300000;j+=i)
                prime[j] = 0;
        }
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %d",&n,&m);
        ch = 0;countt = 0;
        if(n == 2){
            while(m--)
                scanf("%d",&num);
            printf("Case %d: 0\n",i);
        }else{
            for(j=2;j<n;j++)
                if(prime[j])
                    countt++;
            while(m--){
                scanf("%d",&num);
                if(num < n){
                    if(prime[num] && ch == 2)       countt = 0,ch = 3;
                    else if(prime[num] && ch!=3)    countt--;
                    if(num == 1)                    ch = 2;
                }
            }
            if(ch == 3)             printf("Case %d: can't guess\n",i);
            else if(ch == 2)        printf("Case %d: %d\n",i,countt);
            else if(countt == 0)    printf("Case %d: can't guess\n",i);
            else                    printf("Case %d: 1\n",i);
        }
    }
    return 0;
}
/*

*/
