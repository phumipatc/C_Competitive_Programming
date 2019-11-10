/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    int type,r,c,num,w;
    bool operator < (const A & o) const{
        if(w > o.w)     return true;
        else            return false;
    }
};
priority_queue< A> q;
int rr[310],a[310][5100],mark[310][5100],rmark[310];
int main()
{
    A now;
    int r,c,m,round=0,i,j,k,w,ch;
    scanf("%d %d %d",&r,&c,&m);
    for(i=1; i<=r; i++)
        for(j=1; j<=c; j++)
            q.push({1,i,j,1,0});
    for(round=1; round<=m; round++){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %d",&i,&j,&w);
            a[i][j]=w;
            mark[i][j]=round;
            q.push({1,i,j,round,w});
        }
        else if(k==2){
            scanf("%d %d",&i,&w);
            rr[i] = w;
            rmark[i] = round;
            q.push({2,i,0,round,w});
        }
        else if(k==3){
            scanf("%d %d",&i,&j);
            if(mark[i][j]>rmark[i])
                printf("%d\n",a[i][j]);
            else
                printf("%d\n",rr[i]);
        }
        else if(k==4){
            while(!q.empty()){
                now=q.top();
                if(now.type==1){
                    if(now.w!=a[now.r][now.c] || rmark[now.r]>now.num)  q.pop();
                    else{
                            printf("%d\n",now.w);
                            break;
                    }
                }
                else if(now.type==2){
                    if(rmark[now.r]!=now.num) {
                        q.pop();
                        continue;
                    }
                    for(i=1;i<=c;i++){
                        ch=0;
                        if(mark[now.r][i]<now.num){
                            printf("%d\n",now.w);
                            ch=1;
                            break;
                        }
                    }
                    if(ch==0){
                        q.pop();
                        continue;
                    }
                    if(ch)
                        break;
                }
            }
        }
    }
    return 0;
}
