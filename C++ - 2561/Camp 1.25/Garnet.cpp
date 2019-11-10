/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp[100100];
int main(){
    int c,r,sti,stj,now,x,y,n,countt = 0;
    char opr;
    scanf("%d %d %d %d %c",&c,&r,&stj,&sti,&opr);
    if(opr == 'N')      now = 0;
    else if(opr == 'E') now = 1;
    else if(opr == 'S') now = 2;
    else if(opr == 'W') now = 3;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        mapp[y][x] = 1;
    }
    if(mapp[sti][stj] == 1) countt++,mapp[sti][stj] = 2;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&opr);
        if(opr == 'F'){
            if(now == 0 && sti-1>=1)        sti--;
            else if(now == 1 && stj+1<=c)   stj++;
            else if(now == 2 && sti+1<=r)   sti++;
            else if(now == 3 && stj-1>=1)   stj--;
            if(mapp[sti][stj] == 1) countt++,mapp[sti][stj] = 2;
        }else if(opr == 'B'){
            if(now == 0 && sti+1<=r)        sti++;
            else if(now == 1 && stj-1>=1)   stj--;
            else if(now == 2 && sti-1>=1)   sti--;
            else if(now == 3 && stj+1<=c)   stj++;
            if(mapp[sti][stj] == 1) countt++,mapp[sti][stj] = 2;
        }else if(opr == 'L'){
            now = (now-1+4)%4;
        }else if(opr == 'R'){
            now = (now+1)%4;
        }
    }
    printf("%d\n",countt);
	return 0;
}
