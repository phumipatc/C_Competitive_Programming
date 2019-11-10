/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[3000][3000],temp[3000];
int main(){
    int n,l,q,x,y,sum,idx,id;
    char opr;
    scanf("%d %d %d",&n,&l,&q);
    for(int i=1;i<=n;i++){
        a[i][0] = 0;
        for(int j=1;j<=l;j++)
            a[i][j] = j;
    }
    while(q--){
        scanf(" %c",&opr);
        if(opr == 's'){
            scanf("%d %d",&x,&y);
            a[x][0] = a[x][l];
            for(int i=0;i<=l;i++){
                if(i-y>=0)  temp[i] = a[x][i-y];
                else        temp[i] = a[x][i+(l-y)];
            }
            for(int i=0;i<=l;i++)
                a[x][i] = temp[i],printf("%d\n",temp[i]);
        }else if(opr == 'q'){
            sum = 0;
            scanf("%d",&y);
            for(int i=1;i<=n;i++)
                sum+=a[i][y],printf("%d\n",a[i][y]);
            printf("%d\n",sum);
        }else{
            scanf("%d",&x);
            a[x][0] = a[x][l];
            for(int i=0;i<=l;i++){
                if(a[x][i] != l)
                    temp[i] = l-a[x][i];
            }
        }
    }
	return 0;
}
