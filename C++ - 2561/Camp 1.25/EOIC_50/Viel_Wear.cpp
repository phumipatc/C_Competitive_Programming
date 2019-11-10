/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        if(sum+1<num){
            printf("%d\n",sum+1);
            return 0;
        }else{
            sum+=num;
        }
    }
    printf("%d\n",sum+1);
	return 0;
}
