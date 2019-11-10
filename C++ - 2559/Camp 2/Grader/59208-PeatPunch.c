/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[120000],a[120000];
int main(){
    int n,q,pow,ch,i,mark=0;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&h[i]);
        a[i]=h[i];
    }
    while(q--){
        mark++;
        ch=0;
        scanf("%d",&pow);
        for(i=0;i<n;i++){
            h[i]=a[i];
        }
        for(i=0;i<n;i++){
            if(pow<h[i+1]-h[i] && h[i+1]>h[i]){
                ch++;
                h[i+1]=h[i];
            }
        }
        printf("%d\n",ch);
    }
return 0;
}
