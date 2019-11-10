/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[100010];
int main(){
    int z;
    cin >> z;
    if(z<0)
        cout << "-1" << endl;
    else if(z == 0)
        cout << "10" << endl;
    else if(z == 1)
        cout << "1" << endl;
    else{
        int divisor = 9,countt = 0;
        while(divisor>1 && z>1){
            if(z%divisor == 0){
                z = z/divisor;
                ans[countt++] = divisor;
            }else
                divisor--;
        }
        if(z != 1)  cout << "-1";
        else
            for(int i=countt-1;i>=0;i--)
                cout << ans[i];
        cout << endl;
    }
    return 0;
}
