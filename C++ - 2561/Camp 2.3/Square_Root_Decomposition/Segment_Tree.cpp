/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int block[320],a[100010];
int main(){
    int n,q,u,v,sizee,maxx;
    char opr;
    scanf("%d %d",&n,&q);
    sizee = (int )sqrt(n);
    while(q--){
        scanf(" %c %d %d",&opr,&u,&v);
        if(opr == 'U'){
            u--;
            a[u] = v;
            block[u/sizee] = -1e9;
            for(int i=(u/sizee)*sizee;i<min(n,((u/sizee)*sizee)+sizee);i++){
                block[u/sizee] = max(block[u/sizee],a[i]);
            }
        }else{
            u--,v--;
            maxx = -1e9;
            for(int i=u;i<=v;){
                if(i+sizee-1<=v && i%sizee == 0){
                    maxx = max(maxx,block[i/sizee]);
                    i+=sizee;
                }else{
                    maxx = max(maxx,a[i]);
                    i++;
                }
            }
            printf("%d\n",maxx);
        }
    }
	return 0;
}
