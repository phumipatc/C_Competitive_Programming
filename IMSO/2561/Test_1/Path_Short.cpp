/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x1,y1,x2,y2;
};
A a[110];
int main(){
    int m,q,x1,y1,x2,y2,ans;
    scanf("%d %d",&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        ans = 0;
        while(x1!=x2 || y1!=y2){
            if(x1<x2 && y1<y2)          x1++,y1++;
            else if(x1<x2 && y1>y2)     x1++,y1--;
            else if(x1>x2 && y1<y2)     x1--,y1++;
            else if(x1>x2 && y1>y2)     x1--,y1--;
            else if(x1 == x2 && y1<y2)  x1++,y1++;
            else if(x1 == x2 && y1>y2)  x1++,y1--;
            else if(y1 == y2 && x1>x2)  x1--;
            else if(y1 == y2 && x1<x2)  x1++;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
