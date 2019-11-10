/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[750100],n;
void bury(int idx,int value){
    while(idx<=n){
        tree[idx]+=value;
        idx+=(idx & -idx);
    }
}
string a;
int main()
{
    int m,i,r,s;
    scanf("%d %d",&n,&m);
    while(m--){
        cin >> a;
        if(a=="Bury"){
            scanf("%d %d",&r,&s);
            bury(s,r);
        }else if(a=="Find"){
            scanf("%d %d",&r,&s);
            int sum=0;
            while(s>0){
                sum+=tree[s];
                s-=(s & -s);
            }
            r--;
            while(r>0){
                sum-=tree[r];
                r-=(r & -r);
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
/*
10 5
Bury 5 5
Bury 10 7
Find 3 7
Bury 20 8
Find 6 10
*/
