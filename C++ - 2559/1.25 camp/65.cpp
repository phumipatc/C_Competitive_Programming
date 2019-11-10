/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<string.h>
char a[200];
int main()
{
    int len,n=0,s=0,e=0,w=0,i,k,sum;
    scanf(" %s %d",a,&k);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(a[i]=='N')
            n++;
        else if(a[i]=='E')
            e++;
        else if(a[i]=='S')
            s++;
        else if(a[i]=='W')
            w++;
    }
    if(n>=s){
        if(k<=s)
            s-=k,k=0;
        else
            k-=s,s=0;
            sum=n-s;
    }else{
        if(k<=n)
            n-=k,k=0;
        else
            k-=n,n=0;
            sum=s-n;
    }
    if(w>=e){
        if(k<=e)
            e-=k,k=0;
        else
            k-=e,e=0;
            sum+=w-e;
    }else{
        if(k<=w)
            w-=k,k=0;
        else
            k-=w,w=0;
            sum+=e-w;
    }
    sum-=k;
    printf("%d",sum*2);
return 0;
}
