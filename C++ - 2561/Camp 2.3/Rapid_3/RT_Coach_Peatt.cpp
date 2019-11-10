/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int d,m,f;
};
A a[12];
int role[25][3],n;
char str[5];
int permute(int now,int d,int m,int f,int idx){
    if(now == n+1){
        if(d == a[idx].d && m == a[idx].m && f == a[idx].f) return 1;
        else                                                return 0;
    }
    if(role[now][0] && permute(now+1,d+1,m,f,idx))  return 1;
    if(role[now][1] && permute(now+1,d,m+1,f,idx))  return 1;
    if(role[now][2] && permute(now+1,d,m,f+1,idx))  return 1;
    if(permute(now+1,d,m,f,idx))                    return 1;
    return 0;
}
int main(){
    int q,len;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
        scanf("%d-%d-%d",&a[i].d,&a[i].m,&a[i].f);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int j=1;j<=len;j++){
            if(str[j] == 'D')   role[i][0] = 1;
            if(str[j] == 'M')   role[i][1] = 1;
            if(str[j] == 'F')   role[i][2] = 1;
        }
    }
    for(int i=1;i<=q;i++){
        if(permute(1,0,0,0,i))  printf("Yes\n");
        else                    printf("No\n");
    }
	return 0;
}
