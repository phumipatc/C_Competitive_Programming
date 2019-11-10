/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mem[1100],mark[1100],que[1100];
int main(){
    int p,s,m,cur = 1,num;
    scanf("%d %d %d",&p,&s,&m);
    for(int i=1;i<=p;i++)
        scanf("%d",&mem[i]);
    for(int i=1;i<=s;i++){
        scanf("%d",&num);
        if(mark[num]){
            mark[num] = i;
            que[i] = num;
            continue;
        }
        if(m>=mem[num]){
            m-=mem[num];
            mark[num] = i;
            que[i] = num;
            continue;
        }
        while(m<mem[num]){
            if(mark[que[cur]]>cur){
                cur++;
                continue;
            }
            mark[que[cur]] = 0;
            m+=mem[que[cur]];
            cur++;
        }
        m-=mem[num];
        mark[num] = i;
        que[i] = num;
    }
    printf("%d\n",m);
    return 0;
}
