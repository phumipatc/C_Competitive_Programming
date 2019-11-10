/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    for(int i=0;i<=8;i++){
        cout << i << ":" << (double)((1200*i)+10000)/(1200*(i+1)) << endl;
    }
    for(int i=9;i<=25;i++){
        cout << i << ":" << (double)((1200*i)+10000)/10000 << endl;
    }
    return 0;
}
