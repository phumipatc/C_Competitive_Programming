#include<cstdio>
using namespace std;
int a[1000][1000];
int main(){
    int r,c,i,j;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int k=r*c;
    i=j=0;
    printf("%d",a[i][j]);
    while(k--){
        if(j==0){
            i++;
            state=0;
        }else if(i==0){
            j++;
            state=1;
        }
        printf("%d",a[i][j]);
        if(state==0){
            i--,j++;
        }else if(state==1){
            i++,j--;
        }
    }
    return 0;
}
