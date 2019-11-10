/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main(){
    int n,countt = 0,na = 0,nb = 0;
    cin >> n;
    for(int i=1;i<=2*n;i++)
        cin >> a[i];
    for(int i=1;i<=2*n;i++){
        if(a[i]%2 == 0){
            if(a[i-1]%2 == 1)   countt = 0;
            countt++;
            na++;
            if(countt>=3)   na+=2;
            if(na>=n){
                printf("0\n%d\n",a[i]);
                break;
            }
        }else{
            if(a[i-1]%2 == 0)   countt = 0;
            countt++;
            nb++;
            if(countt>=3)   nb+=2;
            if(nb>=n){
                printf("1\n%d\n",a[i]);
                break;
            }
        }
    }
	return 0;
}
