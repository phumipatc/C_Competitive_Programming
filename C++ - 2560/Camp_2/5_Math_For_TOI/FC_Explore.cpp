/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int room[500100];
vector< int> vect[500100];
int main(){
    int n,m,k,i,a,b,num,j;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        vect[a].push_back(b);
    }
    for(i=0;i<k;i++){
        scanf("%d",&num);
        room[num+1]=-1;
    }
    room[1]=1;
    for(i=1;i<=n;i++){
        if(i==1){
            for(j=0;j<vect[i].size();j++){
                room[vect[i][j]]=1;
            }
        }else{
            if(room[i-1]==1 && room[i]!=-1){
                room[i]=1;
            }
            if(room[i]==1){
                for(j=0;j<vect[i].size();j++){
                    room[vect[i][j]]=1;
                }
            }
        }
    }
    //for(i=1;i<=n;i++)   printf("%d ",room[i]);
    //printf("\n");
    if(room[n]==1) printf("1\n");
    else{
        printf("0 ");
        for(i=n;i>0;i--){
            if(room[i]==1){
                printf("%d\n",i);
                break;
            }
        }
    }
	return 0;
}
