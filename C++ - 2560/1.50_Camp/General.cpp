/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int sn[101000],soldier[101000];
int Root(int z){
    if(sn[z]==z)
        return sn[z];
    return sn[z]=Root(sn[z]);
}
int main(){
    int n,m,i,a,b,ra,rb;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        sn[i]=i;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&soldier[i]);
    }
    while(m--){
        scanf("%d %d",&a,&b);
        ra=Root(a);
        rb=Root(b);
        if(ra==rb){
            printf("-1\n");
        }else{
            if(soldier[ra]>soldier[rb]){
                printf("%d\n",ra);
                soldier[ra]+=soldier[rb]/2;
                sn[rb]=ra;
            }else if(soldier[rb]>soldier[ra]){
                printf("%d\n",rb);
                soldier[rb]+=soldier[ra]/2;
                sn[ra]=rb;
            }else{
                if(ra>rb){
                    printf("%d\n",rb);
                    soldier[rb]+=soldier[ra]/2;
                    sn[ra]=rb;
                }else if(rb>ra){
                    printf("%d\n",ra);
                    soldier[ra]+=soldier[rb]/2;
                    sn[rb]=ra;
                }
            }
        }
    }
return 0;
}
