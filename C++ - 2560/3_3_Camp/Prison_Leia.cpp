/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[310];
int main(){
    int A,B,C,a,b,c,d;
    cin >> A >> B >> C;
    if(C == 0){
        printf("1 0 %d %d\n",A,B);
        return 0;
    }
    for(int i=1;i<=A;i++){
        if(A%i!=0)  continue;
        a = i;
        c = A/i;
        for(int j=-abs(C);j<=abs(C);j++){
            if(j == 0 || C%j!=0)    continue;
            b = j;
            d = C/j;
            if((a*d)+(b*c) == B){
                printf("%d %d %d %d\n",a,b,c,d);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}
