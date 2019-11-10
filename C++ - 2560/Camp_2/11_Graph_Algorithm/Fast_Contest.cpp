/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,i,j;
vector <int> V[100100];
vector <int> VT[100100];
queue <int> Q;
int mic[100100];
bool ma[100100],exceed;
void topo(int now){
    ma[now]=true;
    for(int i=0;i<V[now].size();i++){
        if(!ma[V[now][i]])    topo(V[now][i]);
    }
    Q.push(now);
}
int main()
{
    scanf(" %d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf(" %d %d",&a,&b);
        V[a].push_back(b);
        VT[b].push_back(a);
    }
    for(i=1;i<=n;i++){
        if(!ma[i])
            topo(i);
    }
    mic[2]=1;
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        for(i=0;i<VT[now].size();i++){
            mic[VT[now][i]]+=mic[now];
            if(mic[VT[now][i]]>=1000000000)
                exceed=true;
            mic[VT[now][i]]%=1000000000;
        }
    }
    if(exceed)
        printf("%09d",mic[1]);
    else
        printf("%d\n",mic[1]);
    return 0;
}

/*
7 10 1
4
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
-----
4

7 10 2
3 6
1 2 1
1 3 2
4 1 2
2 4 2
3 4 1
4 5 1
4 6 3
5 7 1
7 6 2
4 7 4
-----
8
*/
