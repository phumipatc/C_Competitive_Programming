#include <stdio.h>
int tree[400010];
int size;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void InsertMin(int v){
    size++;
    int now = size;
    tree[now] = v;
    while(now>1 && tree[now/2]>tree[now]){
        swap(&tree[now/2],&tree[now]);
        now/=2;
    }
}
void InsertMax(int v){
    size++;
    int now = size;
    tree[now] = v;
    while(now>1 && tree[now/2]<tree[now]){
        swap(&tree[now/2],&tree[now]);
        now/=2;
    }
}
void MinHeapify(int now){
    int minn = now;
    if(now*2<=size && tree[now*2]<tree[minn])       minn = now*2;
    if(now*2+1<=size && tree[now*2+1]<tree[minn])   minn = now*2+1;
    if(minn == now) return ;
    swap(&tree[now],&tree[minn]);
    MinHeapify(minn);
}
void MaxHeapify(int now){
    int maxx = now;
    if(now*2<=size && tree[now*2]>tree[maxx])       maxx = now*2;
    if(now*2+1<=size && tree[now*2+1]>tree[maxx])   maxx = now*2+1;
    if(maxx == now) return ;
    swap(&tree[now],&tree[maxx]);
    MaxHeapify(maxx);
}
int GetMin(){
    if(size == 0)   return -1;
    if(size == 1){
        size--;
        return tree[1];
    }
    int ret = tree[1];
    tree[1] = tree[size];
    size--;
    MinHeapify(1);
    return ret;
}
int GetMax(){
    if(size == 0)   return -1;
    if(size == 1){
        size--;
        return tree[1];
    }
    int ret = tree[1];
    tree[1] = tree[size];
    size--;
    MaxHeapify(1);
    return ret;
}
int main(){
    int n,num;
    char opr;
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&opr);
        if(opr == 'i'){
            scanf("%d",&num);
            // InsertMin(num);
            InsertMax(num);
        }else{
            // printf("%d\n",GetMin());
            printf("%d\n",GetMax());
        }
    }
    return 0;
}