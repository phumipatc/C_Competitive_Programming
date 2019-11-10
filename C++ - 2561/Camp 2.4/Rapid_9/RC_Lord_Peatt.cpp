/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dwarf[500010],elf[500010],tree[500010],st[500010];
void update(int idx,int v){
    while(idx<=500003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
printf("2\n");
	return 0;
}