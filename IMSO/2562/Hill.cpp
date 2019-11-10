/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int i,j,sti,stj,w,h,s;
    bool operator < (const A&o) const{
        return w<o.w;
    }
};
A now;
priority_queue<A > heap;
int mapp[1010][1010];
int dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
int dis(int x1,int y1,int x2,int y2){
    return abs(x2-x1)+abs(y2-y1);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,p,q,x,y,h,s;
    cin >> m >> n >> p >> q;
    while(p--){
        cin >> y >> x >> h >> s;
        mapp[x][y] = max(mapp[x][y],h);
        heap.push({x,y,x,y,h,h,s});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.w<mapp[now.i][now.j])    continue;
        for(int k=0;k<4;k++){
            int ii = now.i+dir[0][k];
            int jj = now.j+dir[1][k];
            if(ii<0 || jj<0 || ii>=n || jj>=m)  continue;
            h = now.h-(dis(now.sti,now.stj,ii,jj)/now.s);
            if(mapp[ii][jj]>=h)                 continue;
            mapp[ii][jj] = h;
            heap.push({ii,jj,now.sti,now.stj,h,now.h,now.s});
        }
    }
    while(q--){
        cin >> y >> x;
        cout << mapp[x][y] << "\n";
    }
    return 0;
}