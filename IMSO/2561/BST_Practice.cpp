/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define INF 2e8
using namespace std;
int tree[100100],l[100100],r[100100];
int main(){
    int n,num,now,idx = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        tree[i] = l[i] = r[i] = INF;
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        now = 1;
        if(i == 1){
            tree[now] = num;
            printf("*\n");
            continue;
        }
        while(tree[now]!=INF){
            if(num<tree[now]){
                printf("L");
                if(l[now] == INF){
                    idx++;
                    l[now] = idx;
                    tree[idx] = num;
                    break;
                }
                now = l[now];
            }else{
                printf("R");
                if(r[now] == INF){
                    idx++;
                    r[now] = idx;
                    tree[idx] = num;
                    break;
                }
                now = r[now];
            }
        }
        printf("*\n");
    }
    return 0;
}
