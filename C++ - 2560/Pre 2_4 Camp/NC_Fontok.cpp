/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int qs[2200][2200],n,m,q,t;
int changei(int i,int j){
    return 1+(i-1)+(j-1);
}
int changej(int i,int j){
    return n-(i-1)+(j-1);
}
int main(){
    int x,y,ti,i,j;
    scanf("%d %d %d %d",&n,&m,&q,&t);
    while(m--){
        scanf("%d %d %d",&x,&y,&ti);
        if(t-ti>=0){
            qs[max(0,changei(x,y)-(t-ti))][max(0,changej(x,y)-(t-ti))]++;
            qs[max(0,changei(x,y)-(t-ti))][min(2*n-1,changej(x,y)+(t-ti))+1]--;
            qs[min(2*n-1,changei(x,y)+(t-ti))+1][max(0,changej(x,y)-(t-ti))]--;
            qs[min(2*n-1,changei(x,y)+(t-ti))+1][min(2*n-1,changej(x,y)+(t-ti))+1]++;
        }
    }
    for(int i=0;i<=2*n-1;i++){
        for(int j=0;j<=2*n-1;j++){
            if(i>0&&j>0)
                qs[i][j]+=qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1];
            else if(i>0)
                qs[i][j]+=qs[i-1][j];
            else if(j>0)
                qs[i][j]+=qs[i][j-1];
        }
    }
    while(q--){
        scanf("%d %d",&x,&y);
        printf("%d\n",qs[changei(x,y)][changej(x,y)]);
    }
    return 0;
}

