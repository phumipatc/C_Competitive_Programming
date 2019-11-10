/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
void Eucledian(int a,int b,int *x,int *y){
	if(b==0){
		*x=1;
		*y=0;
		return ;
	}
	int u,v;
	Eucledian(b,a%b,&u,&v);
	*x=v;
	*y=u-v*(a/b);
	return ;
}
int inverse(int a,int b){
	int x,y;
	Eucledian(a,b,&x,&y);
	return x%b;
}
int main(){
	int Q,x1,y1,x2,y2,N,R,i,inv;
	long long ans;
	scanf("%d",&Q);
     while(Q--){
          scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
          if(x1>x2 || y1>y2){
			printf("0\n");	continue;
          }
          N=x2-x1+y2-y1;
          R=y2-y1;
          if(N-R>R)	R=N-R;
          ans=1;
          for(i=R+1;i<=N;i++){
			ans*=i;
			ans%=500000003;
          }
          for(i=2;i<=N-R;i++){
			inv=inverse(i,500000003);
			if(inv < 0) inv+=500000003;
			ans*=inv;
			ans%=500000003;
          }
          printf("%lld\n",ans);
     }
     return 0;
}
