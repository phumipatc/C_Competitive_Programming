/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p;
deque<int > deq[4];
void hanoi(int n,int st,int en,int another){
    if(p == 0)  return ;
    if(n == 1){
        deq[en].push_back(deq[st].back());
        deq[st].pop_back();
        p--;
        return ;
    }
    hanoi(n-1,st,another,en);
    if(p){
        deq[en].push_back(deq[st].back());
        deq[st].pop_back();
        p--;
        if(p){
            hanoi(n-1,another,en,st);
        }
    }
}
int main(){
    int q,n;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf("%d %d",&n,&p);
        for(int i=1;i<=n;i++)
            deq[1].push_front(i);
        hanoi(n,1,3,2);
        printf("Case %d:",x);
        printf("\nA: ");
        if(deq[1].empty())  printf("X");
        else{
            while(!deq[1].empty()){
                printf("%d ",deq[1].front());
                deq[1].pop_front();
            }
        }
        printf("\nB: ");
        if(deq[2].empty())  printf("X");
        else{
            while(!deq[2].empty()){
                printf("%d ",deq[2].front());
                deq[2].pop_front();
            }
        }
        printf("\nC: ");
        if(deq[3].empty())  printf("X");
        else{
            while(!deq[3].empty()){
                printf("%d ",deq[3].front());
                deq[3].pop_front();
            }
        }
        printf("\n");
    }
	return 0;
}
