/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[60000];
int GCD(int i,int j){
    if(i%j==0)  return j;
    return GCD(j,i%j);
}
int main()
{
    int q,i,ans;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&a[i]);
        if(i==0){
            ans=a[i];
        }else{
            ans=GCD(a[i],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
