/*
    TASK:Milk
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100],h[100100];
int findroot(int i){
    int temp=i,next;
    while(p[i]!=i)
        i=p[i];
    while(temp!=i){
        next=p[temp];
        p[temp]=i;
        temp=next;
    }
    return i;
}
main(){
    int n,q,i,a,b,roota,rootb;
    char opr;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++){
        p[i]=i;
        h[i]=0;
    }
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        roota=findroot(a);
        rootb=findroot(b);
        if(opr=='c'){
                if(h[roota]>h[rootb])
                    p[rootb]=roota;
                else if(h[rootb]>h[roota])
                    p[roota]=rootb;
                else if(h[roota]==h[rootb]){
                    p[roota]=rootb;
                    h[rootb]++;
                }
        }else if(opr=='q'){
            if(roota==rootb)
                printf("yes\n");
            else
                printf("no\n");
        }
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
