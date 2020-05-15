/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char opr;
    int id;
};
A a[200010];
deque<int > deq;
int num[200010],tree[200010];
void update(int idx){
    while(idx<=200003){
        tree[idx]++;
        idx+=idx & -idx;
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
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c %d",&a[i].opr,&a[i].id);
        if(a[i].opr == 'L')         deq.push_front(a[i].id);
        else if(a[i].opr == 'R')    deq.push_back(a[i].id);
    }
    int now = 1;
    while(!deq.empty()){
        num[deq.front()] = now++;
        deq.pop_front();
    }
    for(int i=1;i<=n;i++){
        // printf("%d %d\n",a[i].id,num[a[i].id]);
        if(a[i].opr == 'L' || a[i].opr == 'R')  update(num[a[i].id]);
        else                                    printf("%d\n",min(query(num[a[i].id]-1),query(n)-query(num[a[i].id])));
    }
	return 0;
}