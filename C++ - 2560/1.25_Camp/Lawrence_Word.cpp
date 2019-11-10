/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	char d[10];
	bool operator<(const A& o)const{
		if(strcmp(d,o.d)<0) return true;
		return false;
	}
};
A c[100000];
int main(){
            int n,m,i=0,p,coun=0,j;
            char a,b[10];
            scanf("%d %d",&n,&m);
            while(m--){
                        scanf(" %c %d",&a,&p);
                        while(p--){
                                    b[coun++]=a;
                        }
            }
            b[n]='\0';
            sort(b,b+n);
            strcpy(c[i++].d,b);
            while(next_permutation(b,b+n)){
                        strcpy(c[i++].d,b);
            }
            sort(c,c+i);
            printf("%d\n",i);
            for(j=0;j<i;j++){
                        printf("%s\n",c[j].d);
            }
            return 0;
}
