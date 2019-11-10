/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int n[120000];
int main()
{
    int i,nu,num,j,countt=0;
    scanf("%d",&nu);
    for(i=0;i<nu;i++){
        scanf("%d",&num);
        n[num]++;
        if(n[num]==1)   countt++;
    }
    while(j){
        if(countt<3){
            if(j%2==0)  printf("Non\n");
            else        printf("Zine\n");
            for(i=1;i<=nu;i++){
                if(n[i]>0){
                    printf("%d ",i);
                    break;
                }
            }
            for(i=nu;i>0;i--){
                if(n[i]>0){
                    printf("%d\n",i);
                    return 0;
                }
            }
        }else{
            if(j%2==1){
                for(i=1;i<=nu;i++){
                    if(n[i]>0)  break;
                }
                n[i]--;
                n[i+1]++;
                if(n[i]==0) countt--;
            }else{
                for(i=nu;i>0;i--){
                    if(n[i]>0)  break;
                }
                n[i]--;
                n[i-1]++;
                if(n[i]==0) countt--;
            }
            j++;
        }
    }
    return 0;
}
