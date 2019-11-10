/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct Point2D{
    int x,y;
};
vector<Point2D> A;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b == 0){
        return b;
    }
    return gcd(b,a%b);
}
vector<pair<int,int>> coor;
int solution() {
    int GCD,countt = 0,ans = 0,ch1 = 0,ch2 = 0;
    for(int i=0;i<A.size();i++){
        if(A[i].x == 0){
            if(A[i].y<0){
                A[i].y = -1;
            }else if(A[i].y>0){
                A[i].y = 1;
            }
            continue;
        }
        if(A[i].y == 0){
            if(A[i].x<0)
                A[i].x = -1;
            else if(A[i].x>0)
                A[i].x = 1;
            continue;
        }
        if(A[i].x<0)   A[i].x*=-1,ch1 = 1;
        if(A[i].y<0)   A[i].y*=-1,ch2 = 1;
        GCD = gcd(A[i].x,A[i].y);
        if(ch1)     A[i].x*=-1,ch1 = 0;
        if(ch2)     A[i].y*=-1,ch2 = 0;
        coor.push_back(make_pair(A[i].x/GCD,A[i].y/GCD));
    }
    sort(coor.begin(),coor.end());
    coor.push_back(make_pair(1e9,1e9));
    for(int i=0;i<coor.size()-1;i++){
        countt++;
        if(coor[i]!=coor[i+1]){
            ans++;
            countt = 0;
        }
    }
    return ans;
}
int main(){
    int n,x,y;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        A.push_back({x,y});
    }
    cout << solution();
    return 0;
}
