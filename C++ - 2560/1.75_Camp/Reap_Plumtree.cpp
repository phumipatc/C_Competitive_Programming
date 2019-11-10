/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <bits/stdc++.h>
using namespace std;
int mic[1010],temp[1010];
int main(){
    int q,n,w,i,t,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&w);
        memset(mic,0,sizeof mic);
        mic[0]=1;
        while(n--){
            scanf("%d",&t);
            memset(temp,0,sizeof temp);
            while(t--){
                scanf("%d",&now);
                for(i=w;i>=now;i--)
                    if(mic[i-now]==1)
                        temp[i]=1;
            }
            for(i=1;i<=w;i++)
                mic[i]=temp[i];
            mic[0]=0;
        }
        int ch=1;
        for(i=w;i>=0;i--){
            if(mic[i]==1){
                printf("%d\n",i);
                ch=0;
                break;
            }
        }
        if(ch)  printf("-1\n");
    }
    return 0;
}
