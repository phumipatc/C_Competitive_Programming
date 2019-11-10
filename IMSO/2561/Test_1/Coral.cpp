/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[5000100],mark[2000100],countt = 0,ch;
int z[25] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
void update(int l,int r,int now,int ll,int rr){
    if(l == ll && r == rr){
        ch = 1;
        tree[now] = 1;
//        printf("Match : %d %d\n",l-1,r-1);
    }
    if(l == r){
        if(!mark[l] && tree[now]){
//            printf("Leaf : %d %d\n",l-1,r-1);
            mark[l] = 1;
            countt++;
        }
        return ;
    }
    if(ch && tree[now*2] == 0 && tree[now*2+1] == 0)    return ;
    int mid = (l+r)/2;
    if(!ch){
        if(rr<=mid) update(l,mid,now*2,ll,rr);
        else        update(mid+1,r,now*2+1,ll,rr);
    }
    if(tree[now*2] && tree[now*2+1]){
//        printf("Child make : %d %d\n",l-1,r-1);
        tree[now] = 1;
        return ;
    }
    if(tree[now]){
        if(tree[now*2] && tree[now*2+1] == 0){
//            printf("Me make right : %d %d\n",mid,r-1);
            tree[now*2+1] = 1;
            update(mid+1,r,now*2+1,ll,rr);
        }else if(tree[now*2+1] && tree[now*2] == 0){
//            printf("Me make left : %d %d\n",l-1,mid-1);
            tree[now*2] = 1;
            update(l,mid,now*2,ll,rr);
        }
    }
}
int main(){
    int n,k,m,zoom,st;
    scanf("%d %d",&k,&m);
    n = z[k];
    for(int i=1;i<=m;i++){
        scanf("%d %d",&zoom,&st);
        ch = 0;
        update(1,n,1,st+1,st+z[zoom]);
        if(countt == n){
            printf("%d\n",i);
            return 0;
        }
    }
	return 0;
}
