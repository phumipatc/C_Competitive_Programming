/*
TASK: Milk
LANG: C
AUTHOR:
*/
#include<stdio.h>
int p[100100];
int findroot(int i){
    if(p[i]==i)
        return p[i];
    return p[i]=findroot(p[i]);
}
int main()
{
    int n,q,i,a,b,roota,rootb;
    char opr;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)   p[i]=i;
    while(q--){
        scanf(" %c %d %d",&opr,&a,&b);
        roota = findroot(a);
        rootb = findroot(b);
        if(opr=='c'){
            p[rootb]=roota;
        }
        else if(opr=='q'){
            if(roota==rootb)    printf("yes\n");
            else                printf("no\n");
        }
    }
    return 0;
}
