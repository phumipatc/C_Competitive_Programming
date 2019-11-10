/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[50],a[4000000],ans[4000000],idx = 1,temp[4000000];
void divide(int n,int pos,int state,int num){
    if(n == 1){
        ans[idx++] = num;
        return ;
    }
    if(a[pos] == 0){
        divide(n/2,pos*2,state+1,num);
        divide(n/2,(pos*2)+1,state+1,num+p[state]);
    }else if(a[pos] == 1){
        divide(n/2,pos*2,state+1,num+p[state]);
        divide(n/2,(pos*2)+1,state+1,num);
    }
}
void divide2(int n,int pos){
    if(n == 1){
        temp[pos] = a[pos];
        return ;
    }
    divide2(n/2,pos*2);
    divide2(n/2,(pos*2)+1);
    if(temp[pos*2]<temp[(pos*2)+1]) a[pos] = 0;
    else                            a[pos] = 1;
    temp[pos] = min(temp[pos*2],temp[(pos*2)+1]);
}
int main(){
    int opr,n;
    char temp;
    scanf("%d",&opr);
    p[0] = 1;
    for(int i=1;i<=25;i++)
        p[i] = p[i-1]*2;
    if(opr == 1){
        scanf("%d",&n);
        for(int i=1;i<p[n];i++){
            scanf(" %c",&temp);
            if(temp == 'L') a[i] = 0;
            else            a[i] = 1;
        }
        divide(p[n],1,0,1);
        for(int i=1;i<min(idx,555556);i++){
            printf("%d ",ans[i]);
        }
    }else if(opr == 2){
        scanf("%d",&n);
        for(int i=0;i<p[n];i++)
            scanf("%d",&a[i+p[n]]);
        divide2(p[n],1);
        for(int i=1;i<p[n];i++){
            if(a[i] == 0)   printf("L");
            else            printf("R");
        }
    }
	return 0;
}
