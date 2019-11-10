/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
int before[300300];
int after[300300];
int findtail(int root){
    if(after[root]==root) return root;
    return root=findtail(after[root]);
}
int main(){
    int n,from,to,taila,tailb,root,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        before[i]=after[i]=i;
    }
    for(i=1;i<=n-1;i++){
        scanf("%d %d",&from,&to);
        if(after[to]!=to){
            //insert
            tailb=findtail(from);
            before[after[to]] = after[tailb];
            before[from]=to;
            after[tailb]=after[to];
            after[to]=from;
        }else if(after[to]==to){
            before[from]=to;
            after[to]=from;
        }
    }
    for(i=1;i<=n;i++)
        if(before[i]==i)
            root=i;
    printf("%d ",root);
    while(after[root]!=root){
        root=after[root];
        printf("%d ",root);
    }
    return 0;
}
