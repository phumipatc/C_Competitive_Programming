/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    char opr;
    long long pluss = 0,minuss = 0,multiply = 1,n,num,ch = 0;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> opr >> num;
        if(opr == '+')  pluss+=num;
        if(opr == '-')  minuss+=num;
        if(opr == 'x'){
            if(num!=0)  multiply*=num;
            else        ch = 1;
        }
    }
    if(ch)  cout << pluss*multiply << endl;
    else    cout << (pluss*multiply)-minuss << endl;
    return 0;
}
