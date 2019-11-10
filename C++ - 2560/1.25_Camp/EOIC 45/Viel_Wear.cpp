/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,a,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        if(sum+1<a){
			printf("%d\n",sum+1);
			return 0;
		}
        else
            sum+=a;
    }
    printf("%d\n",sum+1);
	return 0;
}
