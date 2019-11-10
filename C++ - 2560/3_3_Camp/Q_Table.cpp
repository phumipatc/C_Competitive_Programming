/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,t;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int a[305][5005],ta[305][5005],b[305],tb[305];
int main(){
    int i,j,r,c,m,opr,v;
    cin >> r >> c >> m;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            heap.push({i,j,0,0});
    for(int k=1;k<=m;k++){
        cin >> opr;
        if(opr == 1){
            cin >> i >> j >> v;
            a[i][j] = v;
            ta[i][j] = k;
            heap.push({i,j,v,k});
        }else if(opr == 2){
            cin >> i >> v;
            b[i] = v;
            tb[i] = k;
            heap.push({i,0,v,k});
        }else if(opr == 3){
            cin >> i >> j;
            if(ta[i][j]>tb[i])  printf("%d\n",a[i][j]);
            else                printf("%d\n",b[i]);
        }else{
            int ch;
            while(!heap.empty()){
                now = heap.top();
                if(now.j == 0){
                    if(now.t<tb[now.i]){
                        heap.pop();
                        continue;
                    }
                    ch = 1;
                    for(int j=1;j<=c;j++)
                        if(now.t >= ta[now.i][j])
                            ch = 0;
                    if(ch){
                        heap.pop();
                        continue;
                    }
                    printf("%d\n",now.w);
                    break;
                }else{
                    if(now.t<tb[now.i] || now.t<ta[now.i][now.j]){
                        heap.pop();
                        continue;
                    }
                    printf("%d\n",now.w);
                    break;
                }
            }
        }
    }
    return 0;
}
