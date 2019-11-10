/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[120];
int main()
{
    int k,i,len,n,e,s,w,x,y,b = 0,sum = 0;
    scanf(" %s %d",a,&k);
    len = strlen(a);
    if(len == k){
        printf("0\n");
        return 0;
    }
    n = e = w = s = 0;
    for(i=0;i<len;i++){
        if(a[i] == 'N') n++;
        if(a[i] == 'S') s++;
        if(a[i] == 'W') w++;
        if(a[i] == 'E') e++;
    }
    //printf("OK1\n");
    while(k--){
        if(n<s && n!=0 && s!=0){
            n--;
        }else if(s<n && s!=0 && n!=0){
            s--;
        }else if(w<e && w!=0 &&  e!=0){
            w--;
        }else if(e<w && e!=0 && w!=0){
            e--;
        }else{
            b++;
        }
        //printf("%d %d %d %d\n",n,s,w,e);
    }
    if(n>=s)
        sum+=n-s;
    else if(s>n)
        sum+=s-n;
    if(w>=e)
        sum+=w-e;
    else if(e>w)
        sum+=e-w;
    printf("%d",2*(sum-b));
    return 0;
}
