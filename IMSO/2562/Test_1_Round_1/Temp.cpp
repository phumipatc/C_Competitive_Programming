/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#include<rescuelib.h>
using namespace std;
typedef long long LL;
pair<int ,int > ans;
int main(){
    int r,c,num1,num2,num3,num4,countt = 4;
    get_size(r,c);
    num1 = drop_robot(1,1);
    num2 = drop_robot(1,c);
    num3 = drop_robot(r,1);
    num4 = drop_robot(r,c);
    if(num1 == -1)  countt--;
    if(num2 == -1)  countt--;
    if(num3 == -1)  countt--;
    if(num4 == -1)  countt--;
    if(countt == 4){
        answer(((num1+num2-c+1)/2)+1,((num1+num3-r+1)/2)+1);
    }else if(countt == 3){

    }else if(countt == 2){

    }else if(countt == 1){

    }
    return 0;
}