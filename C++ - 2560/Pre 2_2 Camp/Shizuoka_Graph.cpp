/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int to[300100],mark[300100];
int main(){
    int n,i,q,opr,num,ans,ch;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&to[i]);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&opr,&num);
        if(opr==1){
            i=num,ch=0;
            memset(mark,0,sizeof mark);
            while(to[i]!=i && to[i]!=0){
                if(mark[i]==1){
                    ch=1;
                    break;
                }
                mark[i]=1;
                i=to[i];
            }
            if(ch)
                printf("Cycle\n");
            else
                printf("%d\n",i);
        }else{
            to[num]=num;
        }
    }
    return 0;
}
