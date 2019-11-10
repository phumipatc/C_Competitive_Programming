/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int gcd(int a,int b){
	if(a%b==0){
		return b;
	}else{
		return gcd(b,a%b);
	}
}
int main()
{
    int ans,i,n,num;
    scanf("%d %d",&n,&ans);
    for(i=0;i<n-1;i++){
        scanf("%d",&num);
        ans= gcd(ans,num);
    }
    printf("%d\n",ans);
return 0;
}
