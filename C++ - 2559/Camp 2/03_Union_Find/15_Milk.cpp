/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int A[100100];
int root(int i){
    if(A[i]==i)
        return A[i];
    return A[i]=root(A[i]);
}
int main(){
    char c;
    int n,q,a,b,ra,rb,i;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        A[i]=i;
    while(q--){
        scanf(" %c %d %d",&c,&a,&b);
        ra=root(a);
        rb=root(b);
        if(c=='c'){
            A[rb]=ra;
        }else if(c=='q'){
            if(ra==rb)
                printf("yes\n");
            else
                printf("no\n");
        }
        for(i=1;i<=n;i++)
            printf("%d",A[i]);
    }
return 0;
}
/*
5 10
q 1 2
c 1 3
q 3 2
c 3 2
q 1 2
q 4 5
c 4 2
q 4 1
c 1 4
q 5 1
*/
