/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[15][15];
int main()
{
    int r,c,i,j,degree;
    cin >> r >> c;
    for(int i=1;i<=r;i++)
        cin >> a[i]+1;
    cin >> degree;
    if(degree==0 || degree==360){
        for(i=1;i<=r;i++)
            cout << a[i]+1 << endl;
    }else if(degree==90){
        for(j=1;j<=c;j++){
            for(i=r;i>=1;i--){
                cout << a[i][j];
            }
            cout << endl;
        }
    }else if(degree==180){
        for(i=r;i>=1;i--){
            for(j=c;j>=1;j--){
                cout << a[i][j];
            }
            cout << endl;
        }
    }else if(degree==270){
        for(j=c;j>=1;j--){
            for(i=1;i<=r;i++){
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
/*
3 5
peatt
sukit
flash
*/
