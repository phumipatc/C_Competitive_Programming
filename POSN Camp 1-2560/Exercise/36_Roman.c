/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
int j,d,i,v,x,l,c,k;
int main(){
            scanf("%d",&d);
            for(j=1;j<=d;j++){
		k=j;
		if(k>=300) k-=300 , c+=3;
                        if(k>=200) k-=200 , c+=2;
                        if(k>=100) k-=100 , c++;
                        if(k>=90) k-=90  ,c++ ,x++;
                        if(k>=50) k-=50      , l++;
                        if(k>=40) k-=40      ,x++,l++;
                        if(k>=30) k-=30,x+=3;
                        if(k>=20) k-=20,x+=2;
                        if(k>=10) k-=10,x++;
                        if(k>=9) k-=9,i++,x++;
                        if(k>=5) k-=5,v++;
                        if(k>=4) k-=4,v++,i++;
                        if(k>=3) k-=3,i+=3;
                        if(k>=2) k-=2,i+=2;
                        if(k>=1) k--,i++;
            }
            printf("%d %d %d %d %d",i,v,x,l,c);
}
