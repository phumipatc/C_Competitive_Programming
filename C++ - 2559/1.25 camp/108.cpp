/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int sum,book;
};
A a[500000],c[500000];
int b[1010];
int cmp(const void *a,const void *b){
    A *p,*q;
    p=(A *)a;
    q=(A *)b;
    if(p->sum==q->sum)
        return p->book;
    return p->sum-q->sum;
}
int main()
{
    int n,k,ch=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        b[i]+=b[i-1];
    }infinite;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            a[ch].sum=b[i]-b[j-1];
            a[ch].book=j-i+1;
            ch++;
        }
    }
    qsort(a,ch,sizeof(a[0]),cmp);

    for(i=0;i<ch;i++){
        if(a[i].sum==c[])
    }
    while(k--){
        scanf("%d",&i);
        p=0,q=ch-1;
        while(p<=q){
            mid=(p+q)/2;
            if(a[mid].sum==i){
                break;
            }else if(a[mid].sum<i){
                ans=a[mid.book];
                p=mid+1;
            }else{
                q=mid-1;
            }
        }
    }
return 0;
}
